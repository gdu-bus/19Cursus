/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:04:38 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/01/21 14:52:23 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			x;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!d && !s)
		return (NULL);
	if (d > s)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	else if (d < s)
	{
		x = -1;
		while (++x < len)
			d[x] = s[x];
	}
	return (dst);
}

char	*ft_strjoin(char **s1, const char *s2)
{
	int		x;
	int		y;
	char	*new;

	if (*s1 == NULL && s2 == NULL)
		return (NULL);
	x = ft_strlen(*s1);
	y = ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * (x + y + 1))))
		return (NULL);
	ft_memmove(new, *s1, x);
	y = -1;
	while (s2[++y] != '\0')
		new[y + x] = s2[y];
	new[y + x] = '\0';
	free(*s1);
	return (new);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	int		l;

	l = 0;
	while (src[l])
		++l;
	if (!(dup = malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	size_t x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

int		ft_free(char **stat, int ret)
{
	if (*stat)
	{
		free(*stat);
		*stat = NULL;
	}
	return (ret);
}
