/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:17:35 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/08 16:21:27 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int n;
	unsigned int i;

	if (!*to_find)
		return ((char*)str);
	n = 0;
	while (str[n] != '\0' && (size_t)n < len)
	{
		if (str[n] == to_find[0])
		{
			i = 1;
			while (to_find[i] != '\0' && str[n + i] == to_find[i] &&
					(size_t)(n + i) < len)
				++i;
			if (to_find[i] == '\0')
				return ((char*)&str[n]);
		}
		n++;
	}
	return (0);
}
