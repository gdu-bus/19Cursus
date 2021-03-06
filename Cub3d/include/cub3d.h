/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:46:02 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/11/23 13:06:40 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../minilibx/mlx.h"

/*
** definition structure
*/

typedef struct		s_parse
{
	char			*info;
	char			*map_str;
	char			**map;
	char			dir;
	int				screen_x;
	int				screen_y;
	char			*n_path;
	char			*s_path;
	char			*w_path;
	char			*e_path;
	char			*sp_path;
	int				s;
	int				f;
	int				f1;
	int				f2;
	int				f3;
	int				c;
	int				c1;
	int				c2;
	int				c3;
	int				map_h;
	int				map_w;
	double			pos_ix;
	double			pos_iy;
}					t_parse;

typedef struct		s_check
{
	int				v_r;
	int				v_path_n;
	int				v_path_s;
	int				v_path_w;
	int				v_path_e;
	int				v_path_sp;
	int				v_c;
	int				v_f;
}					t_check;

typedef struct		s_display
{
	int				*addr;
	void			*img;
	int				line_length;
	int				endian;
	int				bits_per_pixel;

}					t_display;

typedef struct		s_texture
{
	void			*color_n;
	void			*color_s;
	void			*color_e;
	void			*color_w;
	int				texx;
	int				texy;
	int				texwidth;
	int				texheight;
	float			texpos;
	int				*color;
	int				texnum;
	float			step;

}					t_texture;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;

}					t_mlx;

typedef struct		s_rec
{
	float			speed;
	float			rotation;
	float			posx;
	float			posy;
	float			dirx;
	float			diry;
	float			olddirx;
	float			olddiry;
	float			planex;
	float			planey;
	float			oldplanex;
	float			camerax;
	float			raydirx;
	float			raydiry;
	unsigned int	mapx;
	unsigned int	mapy;
	float			sidedistx;
	float			sidedisty;
	float			deltadistx;
	float			deltadisty;
	float			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				wallheight;
}					t_rec;

typedef struct		s_spr
{
	int				nbsprites;
	void			*spr_tex;
	int				*color;
	int				sprwidth;
	int				sprheight;
	float			spritex;
	float			spritey;
	float			invdet;
	float			transformx;
	float			transformy;
	int				spritescreenx;
	int				drawstarty;
	int				drawendy;
	int				drawstartx;
	int				drawendx;
	int				stripe;
	int				texx;
	int				texy;
	float			*zbuffer;
	float			*sprites_x;
	float			*sprites_y;
	float			spritedistance;
}					t_spr;

typedef struct		s_data
{
	t_rec			rec;
	t_mlx			mlx;
	t_display		dis;
	t_parse			parse;
	t_texture		tex;
	t_spr			spr;
	t_check			check;
}					t_data;

/*
** launching algo
*/

int					main(int argc, char **argv);
void				ft_init_struct(t_data *data);
void				init_dis(t_data *data);
void				init_parse(t_data *data);
void				init_check(t_data *data);
int					ft_bmp(t_data *data);

/*
** raycasting
*/

int					ft_keyboard(int keycode, t_data *data);
void				ft_start_algo(t_data *data);
void				*start_raycasting(t_data *data);
void				calculate_height(t_data *data);
void				calculate_dist(t_data *data);
void				perform_dda(int hit, t_data *data);
void				step_and_sidedist(t_data *data);
void				ray_and_deltadist(int x, t_data *data);
void				ft_verline(int x, t_data *data);

/*
** parsing
*/

int					ft_parse_cub(t_data *data, char *filename);
int					parse_map(int fd, t_data *data, char *line);
int					parse_info(int fd, t_data *data, int i);
int					ft_check_space(int i, char *str);
int					ft_strlen_parsing(char *str, int i, char c);
int					ft_get_texture(char *str, int i, t_data *data, char c);
int					ft_get_texture_2(char *tab, t_data *data, char c);
void				ft_check_letters(t_data *data, char c);
void				ft_get_size(char *str, int i, t_data *data);
void				ft_get_ceiling(char *str, int i, t_data *data);
void				ft_get_floor(char *str, int i, t_data *data);
int					ft_parsing_lettre(char *str, int i, t_data *data, char c);
int					ft_parsing_info(t_data *data, int i);
int					ft_get_rgb(int i, int j, int k);
char				*create_line(char *str, int diff);
int					ft_size_map(t_data *data, int i);
int					ft_parsing_map(t_data *data);
char				*ft_remove_tab(t_data *data, int i, int j);
int					ft_pass_space(char *str, int i);
void				calculate_colors(t_data *data);
void				calculate_textures(t_data *data);
int					create_images2(t_data *data);
int					create_images1(t_data *data);
int					generate_textures(t_data *data);
int					init_dir(t_data *data);
void				init_n_s(t_data *data);
void				init_e_w(t_data *data);

/*
**		parsing sprites
*/

int					ft_get_sprt(t_data *data);
void				ft_get_sprites(t_data *data);
int					ft_malloc_sprt(t_data *data);

/*
** 		raycast sprites
*/

void				sprites_raycasting(t_data *data);
void				calculate_transform(int i, t_data *data);
void				calculate_draw_start_end(t_data *data);
void				verline_sprites(t_data *data);

/*
** 		ft_position_direction
*/

int					ft_keyboard(int keycode, t_data *data);
void				ft_start_algo(t_data *data);
void				*ft_algo(t_data *data);
void				ft_verline(int x, t_data *data);

/*
** check errors
*/

int					check_errors(t_data *data);
int					check_walls(t_data *data, int k);
int					check_around(int i, int j, t_data *data);
int					check_map_characters(t_data *data);
int					return_error_exit(t_data *data);
int					error_pos_init(t_data *data);
int					check_borders_lines(t_data *data);
int					check_borders_columns(t_data *data);
int					check_pos_init(t_data *data);
int					check_textures(t_data *data);
int					check_path(t_data *data, char *str);
int					check_others(t_data *data);
int					check_info(t_data *data);
int					exit_all(t_data *data);

#endif
