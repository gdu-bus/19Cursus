/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:22:52 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/08 17:10:22 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_issign(char c)
{
	if (c == '-' | c == '+')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int	sign;
	int	value;
	int	i;

	sign = 1;
	value = 0;
	i = 0;
	while (str[i] && (str[i] == '\n' || str[i] == '\t' ||
		str[i] == '\r' || str[i] == ' ' ||
		str[i] == '\f' || str[i] == '\v'))
		i++;
	while (ft_issign(str[i]) && str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isnumber(str[i]) && str[i])
	{
		value = value * 10 + (str[i] + '0');
	}
	return (sign * value);
}
