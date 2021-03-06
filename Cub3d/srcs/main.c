/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:38:12 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/11/26 11:46:51 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_errors(int ac, char **av)
{
  int fd;

  fd = 0;
  if (ac == 1 || ac > 3)
  {
    write(1, "Error\nInvalid arguments\n", 24);
    return (-1);
  }
  else if (ac == 3 &&
    (ft_strncmp(av[2], "--save", 6) || ft_strlen(av[2]) != 6))
  {
    write(1, "Error\nInvalid option\n", 21);
    return (-1);
  }
  else if ((fd = open(av[1], O_RDONLY)) <= 0)
  {
    write(1, "Error\nNo map include\n", 21);
    return (-1);
  }
  if (fd > 0)
    close(fd);
  return (0);
}

int		launch_program(t_data *data, char *av)
{
	ft_init_struct(data);
  if (ft_parse_cub(data, av) < 0)
    return (-1);
  if (!(data->mlx.mlx_ptr = mlx_init()))
  	return (-1);
  data->mlx.mlx_win = mlx_new_window(data->mlx.mlx_ptr,
    data->parse.screen_x, data->parse.screen_y, "cub3D");
  if (generate_textures(data) < 0)
    return (-1);
  data->dis.img = mlx_new_image(data->mlx.mlx_ptr, data->parse.screen_x,
		data->parse.screen_y);
 	data->dis.addr = (int *)mlx_get_data_addr(data->dis.img,
		&data->dis.bits_per_pixel, &data->dis.line_length, &data->dis.endian);
  start_raycasting(data);
  return (1);
}

int   main(int ac, char **av)
{
	t_data		data;

	if (ft_errors(ac, av) < 0)
		return (-1);
	else if (ac == 2)
	{
		if ((launch_program(&data, av[1])) < 0)
			return (exit_all(&data));
		mlx_hook(data.mlx.mlx_win, 2, 1L << 1, ft_keyboard, &data);
		mlx_hook(data.mlx.mlx_win, 17, 0, exit_all, &data);
		mlx_loop(data.mlx.mlx_ptr);
	}
	else if (ac == 3 && !ft_strncmp(av[2], "--save", 5))
	{
		if ((launch_program(&data, av[1])) < 0)
			return (exit_all(&data));
	  ft_bmp(&data);
  }
  else
    exit_all(&data);
  return (0);
}
