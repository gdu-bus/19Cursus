/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:17:29 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/09 08:00:16 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
  if ((nb == 0 && f->precision == 0) || (!put->precision && !put->whidth))
  {
    apply_precision_param_zero(f, put, nb)
  }
}
