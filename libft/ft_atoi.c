/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:22:52 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/15 16:29:30 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_signe(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int						s;
	unsigned long long int	v;

	s = 1;
	v = 0;
	while (*str && ((*str == '\n') || (*str == '\t') ||
				(*str == '\r') || (*str == ' ') ||
				(*str == '\f') || (*str == '\v')))
		str++;
	if (ft_signe(*str) && *str)
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		v = (v * 10) + (*str - '0');
		if (v > 9223372036854775807)
			return ((s + 1) / -2);
		str++;
	}
	return (v * s);
}
