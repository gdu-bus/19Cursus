/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 10:21:38 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/08/18 14:51:37 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void      struc_init(t_f *f)
{
  f->zero = 0;
  f->minus = 0;
  f->width = 0;
  f->precision = -1;
  f->percent = 0;
  f->none = 0;
}

void          init_put(t_put *put)
{
  put->width = 0;
  put->precision = 0;
  put-neg = 0;
}

static void		parser_conditions(t_f *f, char c, char *specs)
{
	if (f->width < 0 && (f->width = -f->width))
		f->minus = 1;
	if (c == '%')
		f->percent = 1;
	if (f->precision < -1)
		f->precision = -1;
	if ((f->precision != -1 || f->minus != 0) && !f->percent)
		f->zero = 0;
	if (ft_check_char(specs, c) == 0)
		f->none = 1;
}

size_t     parser(t_f *f, const char str, va_list arg)
{
  size_t  x;
  char  *specs;

  x = 1;
  specs = "scdiupxX%"
  while (str[x] == '0' && x++)
    f->zero = 1;
  while (str[x] == '-' && x++)
    f->minus = 1;
  while (str[x] == '0')
    x++;
  if (str[x] == '*' && x++)
    f->width = va_arg(arg, int);
  else if (str[x] >= '1' && str[x] <= '9')
    f->width = atoilen(&str[x], &x);
  if (str[x] == '.' && x++)
   {
     if (str[x] '*' && x++)
      f->precision = va_arg(arg, int);
    else
      f->precision = ft_atoilen(&str[x], &x);
   }
   parser_conditions(f, str[x], specs);
   return (x - 1);
}
