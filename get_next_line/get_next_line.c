/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:19:27 by jherrald          #+#    #+#             */
/*   Updated: 2019/12/17 18:19:31 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		temp[BUFFER_SIZE + 1];
	static char	*stat;
	int		x;
	int		ret;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	*line = ft_strdup("");
	if (*stat)
	{
		if ((x = check_stat(*line, temp, stat)) != 0)
			return (x);
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
	{
		buf[ret] = '\0';
		if ((x = check_buf(line, buf, temp, &stat)) != 0)	
	}
}
