/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cleonia <1-d_x_d-1@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:59:44 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/20 14:31:49 by Cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#define MI_CEL_SIZE 10.
#define MI_SIZE 20
#define MI_FIELD_COLOR		0x858585
#define MI_WALL_COLOR 		0xFF0000
#define MI_PLAYER_COLOR		0xFFFF00
#define MI_PLAYER_SIZE		1
#define RAY_COLOR  0xc8c8c8

static void	draw_ray_view(t_all *all, float x, float y)
{
	double	angle;
	int		z;

	angle = -0.5;
	while (angle < 0.5)
	{
		x = (MI_SIZE / 2) * MI_CEL_SIZE;
		y = (MI_SIZE / 2) * MI_CEL_SIZE;
		z = 0;
		while (z++ < 20)
		{
			x += all->player.dir_x * cos(angle) - \
							all->player.dir_y * sin(angle);
			y += all->player.dir_x * sin(angle) + \
							all->player.dir_y * cos(angle);
			if (my_mlx_pixel_get(&all->img, x, y) == MI_WALL_COLOR || \
				my_mlx_pixel_get(&all->img, x, y) == 0 || \
				my_mlx_pixel_get(&all->img, x - 1, y) == 0)
				break ;
			my_mlx_pixel_put(&all->img, x, y, RAY_COLOR);
		}
		angle += 0.01;
	}
}

static void	draw_border_square(t_data *img, int y, int x, int type)
{
	int	i;
	int	j;
	int	size;

	size = MI_CEL_SIZE;
	if (type == 2)
		size = MI_SIZE * MI_CEL_SIZE;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (x + i < 0 || y + j < 0
				|| x + i > SCREEN_WIDTH || y + j > SCREEN_HEIGHT)
				continue ;
			if (i == 0 || j == 0 || i == size - 1 || j == size - 1)
				my_mlx_pixel_put(img, x + i, y + j, 0x000000);
			else if (type == 2)
				my_mlx_pixel_put(img, x + i, y + j, MI_FIELD_COLOR);
			else
				my_mlx_pixel_put(img, x + i, y + j, MI_WALL_COLOR);
		}
	}
}

static void	draw_player(t_data *img)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = (MI_SIZE / 2) * MI_CEL_SIZE;
	y = (MI_SIZE / 2) * MI_CEL_SIZE;
	i = x - MI_PLAYER_SIZE - 1;
	while (++i <= x + MI_PLAYER_SIZE)
	{
		j = y - MI_PLAYER_SIZE - 1;
		while (++j <= y + MI_PLAYER_SIZE)
		{
			if (i < 0 || j < 0)
				continue ;
			my_mlx_pixel_put(img, i, j, MI_PLAYER_COLOR);
		}
	}
}

static void	draw(t_all *all, int mod_x, int mod_y)
{
	int	x;
	int	y;
	int	wall_x;
	int	wall_y;
	int	coef;

	coef = MI_SIZE / 2;
	y = -1;
	while (++y < MI_SIZE)
	{
		x = -1;
		while (++x < MI_SIZE)
		{
			wall_x = (int)all->player.pos_x - coef + x;
			wall_y = (int)all->player.pos_y - coef + y;
			if (wall_x >= 0 && wall_y >= 0 && \
				wall_x < all->map.width && wall_y < all->map.height
				&& all->map.map[wall_x][wall_y] == '1')
				draw_border_square(&all->img, y * MI_CEL_SIZE - mod_y, \
									x * MI_CEL_SIZE - mod_x, 1);
		}
	}
}

void	draw_minimap(t_all *all)
{
	int		coef;
	double	buf;

	coef = MI_SIZE / 2;
	draw_border_square(&all->img, 0, 0, 2);
	draw_player(&all->img);
	draw(all, modf(all->player.pos_x, &buf) * MI_CEL_SIZE, \
			modf(all->player.pos_y, &buf) * MI_CEL_SIZE);
	draw_ray_view(all, (MI_SIZE / 2) * MI_CEL_SIZE, \
						(MI_SIZE / 2) * MI_CEL_SIZE);
}
