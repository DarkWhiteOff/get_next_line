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
	int		nb_read;
	char	*temp;

	nb_read = 1;
	while (nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(save);
			return (NULL);
		}
		else if (nb_read == 0)
			break ;
		buffer[nb_read] = '\0';
		if (save == NULL)
			save = ft_strdup("");
		temp = save;
		save = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (save);
}

char	*prepare_nextline(char	*newLine)
{
	char	*save;
	int		i;

	i = 0;
	while (newLine[i] != '\n' && newLine[i] != '\0')
		i++;
	if (newLine[i] == '\0' || newLine[i + 1] == '\0')
		return (NULL);
	save = ft_substr(newLine, i + 1, ft_strlen(newLine) - i);
	if (save == NULL)
	{
		free(save);
		return (NULL);
	}
	newLine[i + 1] = '\0';
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*new_line;
	static char	*save[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	new_line = read_into_buffer(fd, save[fd], buffer);
	free(buffer);
	if (new_line == NULL)
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	save[fd] = prepare_nextline(new_line);
	return (new_line);
}

/*int	main(void)
{
	int	fd1 = open("1char.txt", O_RDONLY);
	int	fd2 = open ("read_error.txt", O_RDONLY);
	int	line;
	int	i;

	line = 1;
	printf("Line 1 fd1 : %s\n", get_next_line(fd1));
	printf("Line 1 fd2 : %s\n", get_next_line(fd2));
	printf("Line 2 fd1 : %s\n", get_next_line(fd1));
	printf("Line 2 fd2 : %s\n", get_next_line(fd2));
	i = 0;
	while (i < 4)
	{
		printf("Line %d : %s\n", line, get_next_line(fd));
		i++;
		line++;
	}
	return (0);
}*/
