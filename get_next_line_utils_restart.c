/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:47:16 by zamgar            #+#    #+#             */
/*   Updated: 2024/06/12 12:47:18 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_restart.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ss;
	char	*dest;

	i = 0;
	ss = (char *)s;
	while (ss[i] != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (ss[i] != '\0')
	{
		dest[i] = ss[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ftft_strlen(const char *s, unsigned char c)
{
	int	i;

	i = 0;
	if (c != '\0')
	{
		while ((char)s[i] != '\0')
			i++;
	}
	if (c == '\0')
	{
		while ((char)s[i])
		{
			if (s[i + 1] == '\0')
				i++;
			i++;
		}
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int					i;
	unsigned char		cc;

	i = 0;
	cc = (unsigned char)c;
	if (s[0] == '\0' && cc == '\0')
		return ((char *)&s[i]);
	while ((char *)s && i < ftft_strlen(s, cc))
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1len;
	int		s2len;
	int		totalen;
	char	*newstr;

	i = 0;
	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	totalen = s1len + s2len;
	newstr = (char *)malloc(sizeof(char) * totalen + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	newstr[i] = '\0';
	ft_strcat(newstr, (char *)s1);
	ft_strcat(newstr, (char *)s2);
	i = 0;
	while (newstr[i] != '\0')
		i++;
	newstr[i] = '\0';
	return (newstr);
}
