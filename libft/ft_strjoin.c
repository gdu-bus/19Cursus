/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:17:02 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/16 13:09:09 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	join = (char *)malloc(sizeof(char) * (((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (join == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*join = *s1;
		join++;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		*join = *s2;
		join++;
		s2++;
		i++;
	}
	*join = '\0';
	return (join - i);
}
