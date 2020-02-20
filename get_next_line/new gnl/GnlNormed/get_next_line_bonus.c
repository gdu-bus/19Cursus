/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauthier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:56:58 by gauthier          #+#    #+#             */
/*   Updated: 2020/02/19 22:57:33 by gauthier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		adjust_content(int fd, char **line, char **rest)
{
	int		check;

	check = ft_strchr(*line, '\n');
	free(rest[fd]);
	if (check != -1)
	{
		if (!(rest[fd] = ft_strdup(*line + check + 1)))
			return (-1);
		if (!(*line = ft_substr(*line, 0, check)))
			return (-1);
	}
	else
	{
		rest[fd] = NULL;
		return (0);
	}
	return (1);
}

int		read_line(int fd, char **line, char **rest)
{
	int		ret;
	int		check;
	char	*buf;

	if (!(buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	if (!(*line = ft_strdup(rest[fd])))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		check = ft_strchr(*line, '\n');
		if (check != -1)
			break ;
	}
	free(buf);
	if (ret < 0)
		return (-1);
	return (adjust_content(fd, line, rest));
}

int		get_next_line(int fd, char **line)
{
	static char	*rest[OPEN_MAX];

	if (fd < 0 || !line || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	if (!rest[fd])
		if (!(rest[fd] = ft_strdup("")))
			return (-1);
	return (read_line(fd, line, rest));
}
