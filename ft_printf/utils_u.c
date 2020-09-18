/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:24:06 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/18 14:26:00 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_write_unum(unsigned int num, t_put *put)
{
	if (num >= 10)
		ft_write_num((num / 10), put);
	ft_write((num % 10) + '0', put);
}

unsigned int  ft_strlen_uint(unsigned int num)
{
  unsigned int  x;

  if(num == 0)
    return (1);
  x = 0;
  while (num > 0)
  {
    num = num / 10;
    x++;
  }
  return (x);
}
