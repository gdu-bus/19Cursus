/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:31:16 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/17 15:51:49 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		flag_cond_c(t_f *f, t_put *put)
{
	init_put(put);
	if (f->width > 1)
		put->width = f->width - 1;
}

static void		convers_percent(t_f *f, t_put *put, char c)
{
	if (f->zero && !f->minus)
	{
		while (put->width > 0)
		{
			ft_write('0', put);
			put->width--;
		}
		ft_write(c, put);
	}
}

void    convers_c(va_list arg, t_f *f, t_put *put, int i)
{
  char  c;

  flag_cond_c(f, put);
  if (i)
    c = '%';
  if (i && f->zero && !f->minus)
  {
    convers_percent(f, put, c);
    return ;
  }
  if (!i)
    c = va_arg(arg, int);
  if (f->minus)
  {
    ft_write(c, put);
    while (put->width--)
      ft_write(' ', put);
  }
  else if (!f->minus)
  {
    while (put->width--)
      ft_write(' ', put);
    ft_write(c, put);
  }
}
