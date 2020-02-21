/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:49:30 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/02/21 13:31:45 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *line, char *buf);
int		ft_strchr(char *str, char c);
char	*ft_substr(char *str, int start, int size);

#endif
