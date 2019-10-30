/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:36:07 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/07 12:24:57 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;
	char	*b2;

	if (b == NULL)
		return (NULL);
	if (n == 0)
		return (b);
	b2 = b;
	i = 0;
	while (i < n)
	{
		b2[i] = c;
		i++;
	}
	return (b2);
}
