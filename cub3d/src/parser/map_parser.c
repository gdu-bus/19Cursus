/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 19:02:44 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/10/23 18:37:43 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** "+" = vérifie, "-" = vérifie pas : - si il y a plusieurs joueurs
**                                    - si la dernière ligne est ouverte
**                                    + si la premère ligne est complète
**														ou si il y un joueur
*/

int			top_border_map(char **map, size_t x, size_t y, size_t l)
{
	while (is_charset(map[x][y], "1 ") == 1)
	{
		x++;
		l++;
	}
	if (map[x][y] == '\n')
		return (l);
	if (is_charset(map[x][y], "0NESW") == 1 || !is_charset(map[x][y], "1 "))
		return (ERROR);
	else
		top_border_map(**map, x, y, l);
	return (0);
}

int			rest_map(char **map, size_t x, size_t y, size_t l)
{
	if (!map[x][y])
		return (l);
	if (!is_charset(map[x][y], "01NESW \n"))
		return (ERROR);
	while (is_charset(map[x][y], "01NESW ") == 1)
	{
		x++;
		l++;
	}
	if (map[x][y] == '\n')
	{
		y++;
		x = 0;
		rest_map(map, x, y, l);
	}
	rest_map(map, x, y, l);
	return (0);
}

char		map_parser(int fd, char **map)
{
	size_t	l;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if ((l = top_border_map(map, x, y, l)) < 0)
		return (ERROR);
	if ((l = rest_map(map, x, y, l)) < 0)
		return (ERROR);
	return (l);
}
