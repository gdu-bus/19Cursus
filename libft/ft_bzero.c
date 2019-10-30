/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:47:27 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/08 12:18:24 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s2;

	if (s == 0)
		return ;
	i = 0;
	s2 = s;
	while (i < n)
	{
		s2[i] = '\0';
		i++;
	}
}
