/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 13:48:46 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/21 13:49:16 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_write_unum(unsigned int num, t_put *put)
{
	if (num >= 10)
		ft_write_num((num / 10), put);
	ft_write((num % 10) + '0', put);
}

unsigned int	ft_strlen_uint(unsigned int num)
{
	unsigned int x;

	x = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		x++;
	}
	return (x);
}
