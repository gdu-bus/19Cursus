/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauthier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:01:25 by gauthier          #+#    #+#             */
/*   Updated: 2020/02/19 23:01:50 by gauthier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (!(result = (char*)malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (NULL);
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *line, char *buf)
{
	int		i;
	int		j;
	char	*result;

	j = 0;
	i = ft_strlen(line);
	if (!(result = (char*)malloc((i + ft_strlen(buf) + 1) * sizeof(char))))
		return (NULL);
	while (line[j] != '\0')
	{
		result[j] = line[j];
		j++;
	}
	i = 0;
	while (buf[i] != '\0')
	{
		result[j] = buf[i];
		i++;
		j++;
	}
	result[j] = '\0';
	free(line);
	return (result);
}

int		ft_strchr(char *str, char c)
{
	int i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *str, int start, int size)
{
	char	*result;
	int		i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	if (start > i)
		return (ft_strdup(""));
	if (!(result = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	if (size > 0)
	{
		while (str[i] != '\0' && i < size)
		{
			result[i] = str[i + start];
			i++;
		}
	}
	result[i] = '\0';
	free(str);
	return (result);
}
