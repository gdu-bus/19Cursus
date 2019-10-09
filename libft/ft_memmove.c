/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:30:47 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/09 19:09:20 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dest;
	const char		*source;
	unsigned int	i;

	i = 0;
	dest = dst;
	source = src;
	while (i < len)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
