/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 13:21:44 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/04/27 12:42:39 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
  size_t  x;
  va_list arg;
  t_f     f;
  t_put   put;

  x = 0;
  va_start(arg, format);
  put.pos = 0;
  while (format[x])
  {
    if (format [x] == '%')
    {
      struc_init(&f);
      put.len_perc = parser(&f, &format[x], arg);

    }
  }
}
