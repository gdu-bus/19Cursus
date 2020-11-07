/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:10:26 by lorenuar          #+#    #+#             */
/*   Updated: 2020/10/23 14:40:06 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		put_error(int ret, char *s)
{
	put_str_fd(2, ERR"Error\n");
	write(2, s, str_len(s));
	put_str_fd(2, RST"\n"RST);
	return (ret);
}
