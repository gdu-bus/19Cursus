/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:55:22 by lorenuar          #+#    #+#             */
/*   Updated: 2020/10/23 14:02:40 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parser(char *path)
{
	t_fstat fstat;

	fstat = (t_fstat){0, 0, 0, 0, 0, 0};
	(void)fstat;
	if (check_path(path))
		return (put_error(1, BAD_PATH));
	return (0);
}
