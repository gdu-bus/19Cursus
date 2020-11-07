/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:24:07 by lorenuar          #+#    #+#             */
/*   Updated: 2020/10/23 14:08:21 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(int argc, char *argv[])
{
	if (argc == 2 && str_ncmp(argv[1], NO_WINDOW, str_len(NO_WINDOW)) == 0)
	{
		put_str_fd(1, "No window for you\n");
		return (0);
	}
	else if (argc == 2)
	{
		put_str_fd(1, "Showing a window\n");
		return (0);
	}
	return (put_error(EINVAL, "Arg error : please provide an argument"));
}
