/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:11:18 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/09 16:50:51 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void convers_u(va_list arg, t_f *f, t_put *put)
{
  unsigned int    nb;

  nb = va_arg(arg, unsigned int);
  put->len = ft_strlen_uint
}
