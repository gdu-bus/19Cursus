/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:17:29 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/11 12:14:51 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void apply_precision_zero(t_f *f, t_put *put, int nb)
{
  if (nb == 0 && f->precision == 0)
  {
    put->width = f->width;
    while (put->width--)
      ft_write(' ', put);
  }
  if (!put->precision && !put->width)
  {
    if (put->neg)
      ft_write('-', put);
    ft_write_num(nb, put);
  }
}

static void apply_flag(t_f *f, t_put *put, int nb)
{
  if (f->zero)
  {
    if (put->neg)
      ft_write('-', put);
    while (f->width--)
      ft_write('0', put);
    ft_write_num(nb, put);
  }
  if (put->minus)
  {
    if (put->neg)
      ft_write('-', put);
    if (f->precision > 0)
      while (put->precision--)
        ft_write('0', put);
    ft_write_num(nb, put);
    while (f->width--)
      ft_write(' ', put);
  }
}

static void apply_width(t_put *put, int nb)
{
  while (put->width--)
    ft_write(' ', put);
  if (put->neg)
    ft_write('-', put);
  while (put->precision--)
    ft_write('0', put);
  ft_write_num(nb, put);
}

static void apply_precision(t_put *put, int nb)
{
  if (put->neg)
		ft_write('-', put);
  while (put->precision--)
    ft_write('0', put);
  ft_write_num(nb, put);
}

void    convers_d(va_list arg, t_f *f, t_put *put)
{
  int  nb;

  nb = va_arg(arg, int);
  put->len = ft_strlen_int(nb);
  init_put(put);
  if (nb < 0)
  {
    nb = -nb;
    put->neg = 1;
  }
  flag_cond(f, put);
  if ((nb == 0 && f->precision == 0) || (!put->precision && !put->width))
  {
    apply_precision_zero(f, put, nb);
    return ;
  }
  else if (nb == 0 && !f->width && f->precision == -1)
    ft_write('0', put);
  if (f->zero || f->minus)
    apply_flag(f, put, nb);
  else if (!f->minus && !f->zero && put->width)
    apply_width(put, nb);
  if (put->precision && !put->width && !f->zero && !f->minus)
    apply_precision(put, nb);
}
