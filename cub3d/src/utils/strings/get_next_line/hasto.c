/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hasto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:58:26 by lorenuar          #+#    #+#             */
/*   Updated: 2020/10/23 12:11:42 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t		hasto(char *s, char c)
{
	size_t	to;

	to = 0;
	while (s && s[to])
	{
		if (s[to] == c)
			return (to + 1);
		to++;
	}
	if (s && s[to] == c)
		return (to + 1);
	return (0);
}
