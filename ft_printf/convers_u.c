/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 13:46:43 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/21 13:49:34 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_flag(t_f *f, t_put *put, unsigned int nb)
{
	if (f->zero)
	{
		while (put->width--)
			ft_write('0', put);
		ft_write_unum(nb, put);
	}
	if (f->minus)
	{
		if (f->precision > 0)
			while (put->precision--)
				ft_write('0', put);
		ft_write_unum(nb, put);
		while (put->width--)
			ft_write(' ', put);
	}
}

static void	apply_width(t_put *put, unsigned int nb)
{
	while (put->width--)
		ft_write(' ', put);
	while (put->precision--)
		ft_write('0', put);
	ft_write_unum(nb, put);
}

static void	apply_precision(t_put *put, unsigned int nb)
{
	while (put->precision--)
		ft_write('0', put);
	ft_write_unum(nb, put);
}

static void	apply_precision_zero(t_f *f, t_put *put, unsigned int nb)
{
	if (f->precision == 0 && nb == 0)
	{
		put->width = f->width;
		while (put->width--)
			ft_write(' ', put);
	}
	if (!put->precision && !put->width)
		ft_write_unum(nb, put);
}

void		convers_u(va_list arg, t_f *f, t_put *put)
{
	unsigned int		nb;

	nb = va_arg(arg, unsigned int);
	put->len = ft_strlen_uint(nb);
	init_put(put);
	flag_cond(f, put);
	if ((f->precision == 0 && nb == 0) || (!put->precision && !put->width))
	{
		apply_precision_zero(f, put, nb);
		return ;
	}
	else if (nb == 0 && !f->width && f->precision == -1)
		ft_write('0', put);
	if ((f->zero || f->minus) && (f->width || put->precision))
		apply_flag(f, put, nb);
	else if (!f->minus && !f->zero && put->width)
		apply_width(put, nb);
	if (put->precision && !put->width && !f->zero && !f->minus)
		apply_precision(put, nb);
	else if ((f->zero || f->minus) && !f->width && f->precision == -1)
		ft_write_unum(nb, put);
}
