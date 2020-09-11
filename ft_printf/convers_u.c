/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:14:49 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/11 12:28:42 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void apply_precision_zero(t_f *f, t_put *put, int nb)
{
  if (nb == 0 && f->precision)
  {
    put->width = f->width;
    while (put->width--)
      ft_write(' ', put);
  }
  if (!put->precision && put->width)
    ft_write_unum(nb, put);
}

void convers_u(va_list arg, t_f *f, t_put *put)
{
  unsigned int   nb;

  nb = va_arg(arg, unsigned int);
  put->len = ft_strlen_uint(nb);
  init_put(put);
  flag_cond(f, put);
  if((nb == 0 && f->precision == 0) || (!put->precision && put->width))
  {
    apply_precision_zero(f, put, nb);
    return ;
  }
  
}
