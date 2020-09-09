/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:58:27 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/03 13:16:41 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef long long unsigned  t_llu;

/*
** flags
*/

typedef struct  s_f
{
  int     zero;
  int     minus;
  int     wifth
  int     precision;
  int     percent;
  int     none;
}       t_f;

/*
** Copie les esspaces et les zéros des variables et les
** met dans le buffer
*/

typedef struct	s_put
{
	int			width;
	int			precision;
	int			neg;
	int			pos;
	size_t		len;
	size_t		len_perc;
}				t_put;
