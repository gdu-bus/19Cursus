/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:59:06 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/08/31 15:55:56 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int   ft_printf(const char format, ...)
{
  size_t    x;
  t_f     f;
  va_list   arg;
  t_put   put;

  va_start(arg, format);
  put.pos = 0;
  x = 0;
  while (format[x])
  {
    if (format[x] == '%')
    {
      struc_init(&f);
      put.len_perc = flag_parser(&f, &format, arg);
      if (!f.none)
        parser_convers(&format[x + 1], &f, &put, arg);
      x += put.len_perc + 1 -f.none;
    }
    else
      {
        write(1, format[x], 1);
        put->pos++;
      }
      x++;
  }
  va_end(arg);
  return (put.pos);
}
