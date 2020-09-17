/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:58:27 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/16 20:24:07 by gdu-bus-         ###   ########.fr       */
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
  int     width;
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

int				ft_printf(const char *format, ...);
int				ft_atoilen(const char *str, size_t *len);
void			flag_cond(t_f *f, t_put *put);
void			convers_d(va_list arg, t_f *f, t_put *put);
void			convers_u(va_list arg, t_f *f, t_put *put);
void			convers_x(va_list arg, t_f *f, t_put *put, int x);
void			convers_p(va_list arg, t_f *f, t_put *put);
void			convers_s(va_list arg, t_f *f, t_put *put);
void			convers_c(va_list arg, t_f *f, t_put *put, int i);
int				ft_hex_length(long long unsigned int num);
char			ft_hex_conversion(long long unsigned int n, int x);
char			ft_hexa_min(long long unsigned int num, t_put *put, int x);
void			patser_convers(const char *format, t_f *f, t_put *put, va_list arg);
size_t			flag_parser(t_f *f, const char *str, va_list arg);
void			init_put(t_put *put);
void			struc_init(t_f *f);
void			ft_write(const char c, t_put *put);
int				ft_strlen_int(long num);
unsigned int	ft_strlen_uint(unsigned int num);
t_llu			ft_strlen_lluint(unsigned long long num);
void			ft_write_num(long num, t_put *put);
void			ft_write_unum(unsigned int num, t_put *put);
void			ft_write_ullnum(unsigned long long int num, t_put *put); // attention j'ai changé le prototype

#endif
