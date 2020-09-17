/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:58:20 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/16 20:23:46 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void convers_x(va_list arg, t_f *f, t_put *put, int x)
{
  t_llu   nb;

  nb = va_arg(arg, unsigned int);
  put->len = ft_hex_length(nb);
}
