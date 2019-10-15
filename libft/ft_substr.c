/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:54:23 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/15 14:00:10 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*c;

	i = 0;
	if (!s || !len)
		return (NULL);
	c = (char*)malloc(len + 1);
	if (c == NULL)
		return (NULL);
	while (i < start)
		if (*s != '\0')
			i++;
	if (i != start)
		return (NULL);
	while (i < len)
	{
		*(c + i) = *(s + start);
		i++;
		start++;
	}
	c[i] = '\0';
	return (c);
}

