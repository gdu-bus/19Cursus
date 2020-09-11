/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:24:06 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/11 11:38:45 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
