/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:53:19 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/02/06 16:30:30 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_nl(char *str)
{
	int	x;

	x = 0;
	if (str == NULL)
		return (1);
	while (str[x])
	{
		if(str[x] == '\n')
			return (0);
		x++;
	}
	return (1);
}

int		check_stat(char **line, char *buf, char *temp, char *stat)
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
		if (!(*stat =  ft_strdup(&buf[x + 1])))
			return (ft_free(stat, -1));
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		temp[BUFFER_SIZE + 1];
	static char	*stat = NULL;
	int		x;
	int		ret;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if(!(*line = ft_strdup("")))
			return (-1);
	if (stat == NULL)
		stat = ft_strdup("");
	if ((x = check_stat(line, buf, temp, stat)) != 0)
		return (x);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((x = check_buf(line, buf, temp, &stat)) != 0)
			return (x);
	}
	free(stat);
	return (ret);
}

int		main(void)
{
	char	*line;
	int		nb_line;
	int		fd;
	int		i;

	nb_line = 1;
	if ((fd = open("test.c", O_RDONLY)) == -1)
		printf("erreur dans le fichier");
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("line read is :[%d] %s\n", nb_line, line);
		nb_line++;
		free(line);
	}
	printf("line read is : [%d] %s\n", nb_line, line);
	return (0);
}
