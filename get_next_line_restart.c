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

char	*read_into_buffer()
{
	char	*newLine;
	int	nbRead;

	nbRead = 0;
	while (nbRead > 0)
	{
		nbRead = read(fd, buffer, BUFFER_SIZE);
		if ()
	}
	newLine = (char *)malloc(sizeof(char) * );
	if (newLine == NULL)
		return (NULL);
	while (buffer[] != '\0')
	{
		newLine[] = buffer[];
		
	}
	newLine[] = '\0';
	return (newLine);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*newLine;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newLine = read_into_buffer(fd, buffer, BUFFER_SIZE);
}

/*int	main()
{
	int fd = open("test", O_RDONLY);
	int line;
	int i;

	line = 1;
	i = 0;
	//printf("Line 1 : %s\n", get_next_line(fd));
	while (i < 6)
	{
		printf("Line %d : %s\n", line, get_next_line(fd));
		i++;
		line++;
	}
	return (0);
}*/
