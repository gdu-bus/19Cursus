/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:59:23 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/11/25 19:08:52 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calculate_height(t_data *data)
{
	data->rec.wallheight = data->parse.screen_y;
	if (data->rec.perpwalldist == 0)
		data->rec.perpwalldist += 0.1;
	data->rec.lineheight = (int)(data->rec.wallheight / data->rec.perpwalldist);
	data->rec.drawstart = -data->rec.lineheight / 2 + data->parse.screen_y / 2;
	if (data->rec.drawstart < 0)
		data->rec.drawstart = 0;
	data->rec.drawend = data->rec.lineheight / 2 + data->parse.screen_y / 2;
	if (data->rec.drawend >= data->parse.screen_y)
		data->rec.drawend = data->parse.screen_y - 1;
}

void	calculate_dist(t_data *data)
{
	if (data->rec.side == 0)
		data->rec.perpwalldist = (data->rec.mapx - data->rec.posx +
		(1 - data->rec.stepx) / 2) / data->rec.raydirx;
	else
		data->rec.perpwalldist = (data->rec.mapy - data->rec.posy +
		(1 - data->rec.stepy) / 2) / data->rec.raydiry;
	if (data->rec.perpwalldist == 0)
		data->rec.perpwalldist = 0.1;
}

void	perform_dda(int hit, t_data *data)
{
	while (hit == 0)
	{
		if (data->rec.sidedistx < data->rec.sidedisty)
		{
			data->rec.sidedistx += data->rec.deltadistx;
			data->rec.mapx += data->rec.stepx;
			data->rec.side = 0;
		}
		else
		{
			data->rec.sidedisty += data->rec.deltadisty;
			data->rec.mapy += data->rec.stepy;
			data->rec.side = 1;
		}
		if (data->parse.map[data->rec.mapy][data->rec.mapx] == '1')
			hit = 1;
	}
}

void	step_and_sidedist(t_data *data)
{
	if (data->rec.raydirx < 0)
	{
		data->rec.stepx = -1;
		data->rec.sidedistx = (data->rec.posx - data->rec.mapx)
			* data->rec.deltadistx;
	}
	else
	{
		data->rec.stepx = 1;
		data->rec.sidedistx = (data->rec.mapx + 1.0 - data->rec.posx)
			* data->rec.deltadistx;
	}
	if (data->rec.raydiry < 0)
	{
		data->rec.stepy = -1;
		data->rec.sidedisty = (data->rec.posy - data->rec.mapy)
			* data->rec.deltadisty;
	}
	else
	{
		data->rec.stepy = 1;
		data->rec.sidedisty = (data->rec.mapy + 1.0 - data->rec.posy)
			* data->rec.deltadisty;
	}
}

void	ray_and_deltadist(int x, t_data *data)
{
  data->rec.camerax = 2 * x / (float)data->parse.screen_x - 1;
  data->rec.raydirx = data->rec.dirx + data->rec.planex * data->rec.camerax;
  data->rec.raydiry = data->rec.diry + data->rec.planey * data->rec.camerax;
  data->rec.mapx = (int)data->rec.posx;
  data->rec.mapy = (int)data->rec.posy;
  data->rec.deltadistx = fabs(1 / data->rec.raydirx);
  data->rec.deltadisty = fabs(1 / data->rec.raydiry);
}
