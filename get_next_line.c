/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:44:13 by zamgar            #+#    #+#             */
/*   Updated: 2024/06/07 18:26:45 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char	*newLine;
	int	nbRead;
	static int	i;
	int	count;
	int	z;

// while (buffer[BUFFER_SIZE] a encore de la place qui entoure tout
	count = 0;
	if (buffer[i - 1] == '\n')
	{
		buffer[i - 1] = '\0';
		i--;
	}
	z = i;
	while (buffer[i - 1] != '\n')
	{
		nbRead = read(fd, &buffer[i], 1);
		if (nbRead == -1 ||  nbRead < 0)
			return (NULL);
		if (nbRead == 0)
			return (NULL);
		count++;
		i++;
	}
	printf("Full buffer : %s", buffer);
	newLine = (char *)malloc(sizeof(char) * count);
	count = 0;
	while (buffer[z] != '\0')
	{
		newLine[count] = buffer[z];
		count++;
		z++;
	}
	newLine[count] = '\0';
	return (newLine);
}

int	main(void)
{
	int	fd = open("test.c", O_RDONLY);
	int	i;
	int	lineNb;

	lineNb = 1;
	while (i < 6)
	{
		printf("Line %d : %s\n\n", lineNb, get_next_line(fd));
		i++;
		lineNb++;
	}
	close(fd);
	return (0);
}
