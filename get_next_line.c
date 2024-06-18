/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:47:04 by zamgar            #+#    #+#             */
/*   Updated: 2024/06/12 12:47:06 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*read_into_buffer(int fd, char *save, char *buffer)
{
	int	nbRead;
	char	*temp;

	nbRead = 1;
	while (nbRead > 0)
	{
		nbRead = read(fd, buffer, BUFFER_SIZE);
		if (nbRead < 0)
		{
			free(save);
			return (NULL);
		}
		if (nbRead == 0)
			break ;
		buffer[nbRead] = '\0';
		if (save == NULL)
			save = ft_strdup("");
		temp = save;
		save = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (save);
}

char	*prepare_nextline(char	*newLine)
{
	char	*save;
	int	i;

	i = 0;
	while(newLine[i] != '\n' && newLine[i] != '\0')
		i++;
	if (newLine[i] == 0 || newLine[i + 1] == 0)
		return (NULL);
	save = ft_substr(newLine, i + 1, ft_strlen(newLine) - i);
	if (save == NULL)
	{
		free(save);
		return (NULL);
	}
	return (save);
}

char	*prepare_newline(char	*newLine)
{
	int	i;

	i = 0;
	while(newLine[i] != '\n' && newLine[i] != '\0')
		i++;
	if (newLine[i] == 0 || newLine[i + 1] == 0)
		return (newLine);
	newLine[i + 1] = '\0';
	return (newLine);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*newLine;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	newLine = read_into_buffer(fd, save, buffer);
	free(buffer);
	if (newLine == NULL)
		return (NULL);
	save = prepare_nextline(newLine);
	newLine = prepare_newline(newLine);
	return (newLine);
}

/*int	main()
{
	int fd = open("test", O_RDONLY);
	int line;
	int	i;

	line = 1;
	i = 0;
	while (i < 6)
	{
		printf("Line %d : %s\n", line, get_next_line(fd));
		i++;
		line++;
	}
	return (0);
}*/
