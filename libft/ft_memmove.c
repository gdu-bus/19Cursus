/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:30:47 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/14 12:30:51 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*dest;
	const char		*source;

	dest = dst;
	source = src;
	if (dest < source)
	{
		while (n-- > 0)
			*dest++ = *source++;
	}
	else if (dest > source)
	{
		dest += n;
		source += n;
		while (n-- > 0)
			*--dest = *--source;
	}
	return (dest);
}
