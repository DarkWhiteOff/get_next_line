/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:30:54 by zamgar            #+#    #+#             */
/*   Updated: 2024/06/24 13:30:56 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char				*get_next_line(int fd);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcat(char *dest, char *src);
char				*ft_strchr(const char *s, int c);
int					ftft_strlen(const char *s, unsigned char c);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *str, unsigned int start, size_t len);
char				*ft_gen(char *newstr, char const *str,
						unsigned int s, size_t len);
size_t				ft_calc(char const *str, unsigned int start, size_t len);

#endif
