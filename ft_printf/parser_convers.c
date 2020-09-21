/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_convers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 13:48:29 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/21 13:49:19 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parser_convers(const char *format, t_f *f, t_put *put, va_list arg)
{
	if (format[put->len_perc] == 'd' || format[put->len_perc] == 'i')
		convers_d(arg, f, put);
	if (format[put->len_perc] == 'u')
		convers_u(arg, f, put);
	if (format[put->len_perc] == 'x')
		convers_x(arg, f, put, 0);
	if (format[put->len_perc] == 'X')
		convers_x(arg, f, put, 1);
	if (format[put->len_perc] == 'p')
		convers_p(arg, f, put);
	if (format[put->len_perc] == 's')
		convers_s(arg, f, put);
	if (format[put->len_perc] == 'c')
		convers_c(arg, f, put, 0);
	if (format[put->len_perc] == '%')
		convers_c(arg, f, put, 1);
}
