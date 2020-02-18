/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:26:29 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/02/18 18:59:48 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		check_nl(char *str)
{
	int	x;

	x = 0;
	if (str == NULL)
		return (1);
	while (str[x])
	{
		if (str[x] == '\n')
			return (0);
		x++;
	}
	return (1);
}

int		check_stat(char **line, char *temp, char *stat)
{
	int	x;

	if (check_nl(stat))
	{
		if (!(*line = ft_strjoin(line, stat)))
			return (ft_free(&stat, -1));
		stat = NULL;
	}
	else
	{
		x = -1;
		while (stat[++x] != '\n' && stat[x])
			temp[x] = stat[x];
		temp[x] = '\0';
		if (!(*line = ft_strjoin(line, temp)))
			return (ft_free(&stat, -1));
		stat = ft_memmove(stat, &stat[x + 1], ft_strlen(stat) - x);
		return (1);
	}
	return (0);
}

int		check_buf(char **line, char *buf, char *temp, char **stat)
{
	int	x;

	if (check_nl(buf))
	{
		if (!(*line = ft_strjoin(line, buf)))
			return (ft_free(stat, -1));
	}
	else
	{
		x = -1;
		while (buf[++x] != '\n' && buf[x])
			temp[x] = buf[x];
		temp[x] = '\0';
		if (!(*line = ft_strjoin(line, temp)))
			return (ft_free(stat, -1));
		free(*stat);
		if (!(*stat = ft_strdup(&buf[x + 1])))
			return (ft_free(stat, -1));
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		temp[BUFFER_SIZE + 1];
	static char	*stat[OPEN_MAX];
	int			x;
	int			ret;

	if (!line || BUFFER_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	if (stat[fd] == NULL)
		stat[fd] = ft_strdup("");
	if ((x = check_stat(line, temp, stat[fd])) != 0)
		return (x);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((x = check_buf(line, buf, temp, &stat[fd])) != 0)
			return (x);
	}
	free(stat[fd]);
	return (ret);
}
