/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 13:48:59 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/21 13:49:04 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoilen(const char *str, size_t *len)
{
	int						x;
	unsigned long long int	nb;
	int						symb;

	x = 0;
	nb = 0;
	symb = 1;
	while (str[x] == '\t' || str[x] == '\v' || str[x] == '\n'
			|| str[x] == '\r' || str[x] == '\f' || str[x] == ' ')
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x++] == '-')
			symb = symb * (-1);
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		nb = (nb * 10) + (str[x] - 48);
		if (nb > LONG_MAX)
			return ((symb + 1) / -2);
		x++;
		(*len)++;
	}
	return ((int)(nb * symb));
}

void	ft_write(const char c, t_put *put)
{
	write(1, &c, 1);
	put->pos++;
}
