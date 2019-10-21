/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:58:31 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/21 17:51:05 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	long_mot(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int				nbr_mots(char *str, char sep)
{
	int		result;
	int		i;

	i = 0;
	result = 0;
	while (str[i] && str[i] == sep)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != sep)
			i++;
		result++;
		while (str[i] && str[i] == sep)
			i++;
	}
	return (result);
}

static char		*mot_suiv(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static void		cleanup(char **split, size_t n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	size_t	n;
	size_t	nbrmot;

	if (!s || !c)
		return (NULL);
	nbrmot = nbr_mots((char *)s, c);
	split = (char **)malloc((nbrmot + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	n = 0;
	while (n < nbrmot)
	{
		s = mot_suiv(s, c);
		split[n] = ft_substr(s, 0, long_mot(s, c));
		if (split[n] == NULL)
		{
			cleanup(split, n);
			return (NULL);
		}
		n++;
		s += long_mot(s, c);
	}
	split[nbrmot] = NULL;
	return (split);
}
