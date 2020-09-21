/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 13:47:00 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/21 13:49:36 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_flag(t_f *f, t_put *put, t_llu nb, int x)
{
	if (f->zero)
	{
		while (put->width--)
			ft_write('0', put);
		ft_hexadecimal(nb, put, x);
	}
	if (f->minus)
	{
		if (f->precision > 0)
			while (put->precision--)
				ft_write('0', put);
		ft_hexadecimal(nb, put, x);
		while (put->width--)
			ft_write(' ', put);
	}
}

static void	apply_width(t_put *put, t_llu nb, int x)
{
	while (put->width--)
		ft_write(' ', put);
	while (put->precision--)
		ft_write('0', put);
	ft_hexadecimal(nb, put, x);
}

static void	apply_precision(t_put *put, t_llu nb, int x)
{
	while (put->precision--)
		ft_write('0', put);
	ft_hexadecimal(nb, put, x);
}

static void	apply_precision_zero(t_f *f, t_put *put, t_llu nb, int x)
{
	if (f->precision == 0 && nb == 0)
		while (f->width--)
			ft_write(' ', put);
	if (nb != 0)
		ft_hexadecimal(nb, put, x);
}

void		convers_x(va_list arg, t_f *f, t_put *put, int x)
{
	t_llu	nb;

	nb = va_arg(arg, unsigned int);
	put->len = ft_hex_len(nb);
	init_put(put);
	flag_cond(f, put);
	if (nb == 0 && (!f->width || f->width == 1)
			&& (f->precision == -1 || f->precision == 1))
		ft_hexadecimal(nb, put, x);
	if ((f->precision == 0 && nb == 0) || (!put->precision && !put->width))
	{
		apply_precision_zero(f, put, nb, x);
		return ;
	}
	if ((f->zero || f->minus) && (f->width || put->precision))
		apply_flag(f, put, nb, x);
	else if (!f->minus && !f->zero && put->width)
		apply_width(put, nb, x);
	if (put->precision && !put->width && !f->zero && !f->minus)
		apply_precision(put, nb, x);
	else if ((f->zero || f->minus) && !f->width && f->precision == -1)
		ft_hexadecimal(nb, put, x);
}
