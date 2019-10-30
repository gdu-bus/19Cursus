/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:30:47 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/25 14:16:58 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			x;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if ((dst == NULL && src == NULL) || !dst)
		return (NULL);
	if (d > s && dst != src)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	else if (d < s && dst != src)
	{
		x = 0;
		while (x < len)
		{
			d[x] = s[x];
			x++;
		}
	}
	return (dst);
}
