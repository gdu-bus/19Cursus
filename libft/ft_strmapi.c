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
	char	*mapi;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(mapi = ft_strdup((char *)s)))
		return (NULL);
	i = 0;
	while (mapi[i] != '\0')
	{
		mapi[i] = f((unsigned int)i, mapi[i]);
		i++;
	}
	return (mapi);
}
