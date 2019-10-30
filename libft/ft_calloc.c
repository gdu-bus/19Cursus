/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:50:04 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/25 16:29:04 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	if (count == 0 || size == 0)
		return (NULL);
	if (!(result = malloc(size * count)))
		return (NULL);
	while (i <= count)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}
