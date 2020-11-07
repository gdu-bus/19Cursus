/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jointo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:58:26 by lorenuar          #+#    #+#             */
/*   Updated: 2020/10/23 12:43:22 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*jointo(char *s1, char *s2, char **tofree)
{
	char	*a;
	size_t	sl1;
	size_t	sl2;
	size_t	i;

	a = NULL;
	sl1 = hasto(s1, '\0');
	sl2 = hasto(s2, '\0');
	if (!(a = (char *)malloc((sl1 + sl2 + 1) * sizeof(char))))
	{
		if (tofree && *tofree)
			free(*tofree);
		return (NULL);
	}
	i = 0;
	while (sl1 && s1 && *s1 && *s1 != '\n')
		a[i++] = *s1++;
	while (sl2 && s2 && *s2 && *s2 != '\n')
		a[i++] = *s2++;
	a[i] = '\0';
	if (tofree && *tofree)
		free(*tofree);
	return (a);
}
