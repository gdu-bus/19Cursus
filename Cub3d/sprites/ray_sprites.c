/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:15:17 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/11/26 11:38:23 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_switch_sprites(t_data *data, int i, int j)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = data->spr.sprites_x[i];
	tmp_y = data->spr.sprites_y[i];
	data->spr.sprites_x[i] = data->spr.sprites_x[j];
	data->spr.sprites_y[i] = data->spr.sprites_y[j];
	data->spr.sprites_x[j] = tmp_x;
	data->spr.sprites_y[j] = tmp_y;
}

void	ft_sort_sprite(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->spr.nbsprites - 1)
	{
		data->spr.spritedistance = ((data->rec.posx - data->spr.sprites_x[i]) *
			(data->rec.posx - data->spr.sprites_x[i]) +
			(data->rec.posy - data->spr.sprites_y[i]) *
			(data->rec.posy - data->spr.sprites_y[i]));
		j = i + 1;
		while (j < data->spr.nbsprites)
		{
			if (((data->rec.posx - data->spr.sprites_x[j]) * (data->rec.posx -
				data->spr.sprites_x[j]) + (data->rec.posy -
				data->spr.sprites_y[j]) * (data->rec.posy -
				data->spr.sprites_y[j])) > data->spr.spritedistance)
			{
				ft_switch_sprites(data, i, j);
			}
			j++;
		}
		i++;
	}
}

void  sprites_raycasting(t_data *data)
{
  int   i;

  i = 0;
  ft_sort_sprite(data);
  while (i < data->spr.nbsprites)
  {
    calculate_transform(i, data);
    calculate_draw_start_end(data);
    verline_sprites(data);
    i++;
  }
}
