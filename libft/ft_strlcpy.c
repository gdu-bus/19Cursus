/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:59:50 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/14 17:08:32 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	size_t	n;

	if (size == 0)
		return (ft_strlen(src));
	n = 0;
	while (size-- > 1 && *src)
	{
		*dest = *src;
		dest++;
		src++;
		n++;
	}
	*dest = '\0';
	while (*dest || *src)
	{
		if (*src)
		{
			src++;
			n++;
		}
	}
	return (n);
}
