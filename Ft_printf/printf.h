/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:16:10 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/05/01 19:44:41 by gdu-bus-         ###   ########.fr       */
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
# include "../libft/libft.h"

typedef long long unsigned  t_ll;

/*
** Flag activate
*/

typedef struct  s_flag
{
  int       zero;
  int       minus;
  int       whidt;
  int       precision;
  int       percent;
  int       none;
}         t_flag;

/*
** Copy the amounts of zeros or spaces in these variables to add them
** in the buffer
*/

typedef struct  s_put
{
  int
}
