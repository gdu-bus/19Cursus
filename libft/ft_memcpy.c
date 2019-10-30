/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:37:59 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/25 16:33:26 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	i = 0;
	if (s1 == 0)
		return (NULL);
	if (s1 == s2)
		return (s1);
	if (!s1 && !s2)
		return (s1);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}
