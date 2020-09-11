/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 14:01:48 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/11 12:14:27 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int   ft_strlen_int(long num)
{
  int x;

  x = 0;
  if (num == 0)
    return (1);
  if (num < 0)
    num *= -1;
  while (num > 0)
  {
    num = num / 10;
    x++;
  }
  return (x);
}

void   flag_cond(t_f *f, t_put *put)
{
  if (f->precision != -1 && f->precision > (int)put->len)
    put->precision = f->precision - put->len;
  if (f->width > f->precision && (size_t)f->width > put->len)
    put->width = f->width - put->precision - put->neg - put->len;
}

void ft_write_num(long num, t_put *put)
{
  if (num < 0)
    num = -num;
  if (num >= 10)
    ft_write_num((num / 10), put);
  ft_write((num % 10) + '0', put);
 }
