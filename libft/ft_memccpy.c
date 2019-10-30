/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:59:46 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/14 15:02:50 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest1;
	const unsigned char	*src1;

	if (n)
	{
		dest1 = dest;
		src1 = src;
		while (n-- != 0)
		{
			if ((*dest1++ = *src1++) == (unsigned char)c)
				return (dest1);
		}
	}
	return (0);
}
