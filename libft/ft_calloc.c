/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:50:04 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/10 11:07:27 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t nmem, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	if (nmem == 0 || size == 0)
		return (NULL);
	result = malloc(size * nmem);
	while (i <= nmem)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}
