/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 13:48:40 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/21 13:49:17 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		p_cond(t_f *f, t_put *put)
{
	if (put->width)
		put->width++;
	if (f->minus)
	{
		ft_write('0', put);
		ft_write('x', put);
		while (put->width--)
			ft_write(' ', put);
	}
	if (!f->minus)
	{
		while (put->width--)
			ft_write(' ', put);
		ft_write('0', put);
		ft_write('x', put);
	}
}
