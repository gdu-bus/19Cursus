/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:52:15 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/10/08 13:08:59 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (n > 0))
	{
		if (s1[i] == s2[i])
			i++;
		n--;
	}
	return (s1[i] - s2[i]);
}
