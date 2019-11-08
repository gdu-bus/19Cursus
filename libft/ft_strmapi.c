/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:27:48 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/17 16:17:59 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	if (s)
	{
		new = ft_strdup((const char *)s);
		if (new == NULL)
			return (NULL);
		i = 0;
		while (new[i] != 0)
		{
			new[i] = f((unsigned int)i, new[i]);
			i++;
		}
		return (new);
	}
	else
		return (NULL);
}
