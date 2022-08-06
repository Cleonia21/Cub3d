/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:58:36 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/20 18:46:04 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	start_side;
	int		mouse_x;
}	t_player;

typedef struct s_map
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor_color;
	int		ceilling_color;
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_sprite_coordinate
{
	double		x;
	double		y;
	int			texture_flag;
	int			texture_name;
}	t_coordinate;

typedef struct s_sprites
{
	t_data			*texture_light;
	t_data			*texture_barrel;
	int				coller;
	int				coller_max;
	int				coller_min;
	int				coller_mod;
	t_coordinate	*coordinates;
	int				num;
	int				*distance;
	int				*iterator;
	double			*z_buffer;
}	t_sprites;

typedef struct s_fog
{
	int		flag;

	t_data	*clear_wall;
	t_data	*clear_barrel;
	int		clear_floor;
	int		clear_ceilling;

	t_data	*fog_wall;
	t_data	*fog_barrel;
	int		fog_floor;
	int		fog_ceilling;
}	t_fog;

typedef struct s_all
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_data		*wall;
	t_player	player;
	t_map		map;
	t_sprites	sprites;
	t_fog		fog;
}	t_all;

typedef struct s_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		draw_start;
	int		draw_end;
	int		line_height;
}	t_raycast;

#endif