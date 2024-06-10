#include "get_next_line.h"
//#include <fcntl.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char	*newLine;
	int	nbRead;
	static int	i;
	int	count;
	int	z;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (buffer[i] != '\0')
		i++;
	z = i;
	count = 0;
	nbRead = read(fd, &buffer[i], 1);
	if (nbRead <= 0)
		return (NULL);
	while (nbRead > 0)
	{
		if (buffer[i] == '\n')
		{
			i++;
			count++;
			break ;
		}
		i++;
		count++;
		nbRead = read(fd, &buffer[i], 1);
	}
	newLine = (char *)malloc(sizeof(char) * count + 1);
	if (newLine == NULL)
		return (NULL);
	count = 0;
	while (buffer[z] != '\0')
	{
		newLine[count] = buffer[z];
		z++;
		count++;
	}
	newLine[count] = '\0';
	return (newLine);
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
