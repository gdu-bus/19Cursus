/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:58:26 by lorenuar          #+#    #+#             */
/*   Updated: 2020/10/23 12:11:38 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				get_next_line(int fd, char **line)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	ssize_t		ret;
	size_t		i;

	ret = 1;
	i = 0;
	if (BUFFER_SIZE < 1 || fd < 0 || fd >= FOPEN_MAX || !line ||
	!(*line = jointo(buf[fd], NULL, NULL)))
		return (-1);
	while (!hasto(buf[fd], '\n') && ret)
	{
		if ((ret = read(fd, &buf[fd], BUFFER_SIZE)) == -1)
			return (-1);
		buf[fd][ret] = '\0';
		if (!(*line = jointo(*line, buf[fd], line)))
			return (-1);
	}
	ret = hasto(buf[fd], '\n');
	if (ret == 0)
		return (0);
	while (buf[fd][ret] && ret)
		buf[fd][i++] = buf[fd][ret++];
	buf[fd][i] = '\0';
	return (1);
}
