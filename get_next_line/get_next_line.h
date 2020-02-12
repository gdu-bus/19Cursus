/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:38:16 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/02/12 16:53:07 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 99999
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

int			get_next_line(int fd, char **line);
int		ft_free(char **stat, int ret);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char **s1, const char *s2);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);

#endif
