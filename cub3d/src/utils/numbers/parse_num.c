/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:33:42 by lorenuar          #+#    #+#             */
/*   Updated: 2020/10/23 12:11:34 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t		parse_num(const char *s)
{
	size_t	num;
	int		sign;

	num = 0;
	sign = 1;
	while (s && ((*s >= '\t' && *s <= '\r') || *s == ' '))
		s++;
	if (s && *s == '-')
		sign = -1;
	if (s && (*s == '-' || *s == '+'))
		s++;
	while (s && *s >= '0' && *s <= '9')
		num = (num * 10) + (*s++ - '0');
	if (num > LONG_MAX)
		return ((sign == 1) ? -1 : 0);
	return ((sign == 1) ? num : -num);
}
