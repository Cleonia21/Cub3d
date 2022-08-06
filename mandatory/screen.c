/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cleonia <1-d_x_d-1@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:00:03 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/20 14:09:11 by Cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda_algorithm(t_all *all, t_raycast *raycast)
{
	while (raycast->hit == 0)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (all->map.map[raycast->map_x][raycast->map_y] == '1')
			raycast->hit = 1;
	}
	if (raycast->side == 0)
		raycast->perp_wall_dist = raycast->side_dist_x - raycast->delta_dist_x;
	else
		raycast->perp_wall_dist = raycast->side_dist_y - raycast->delta_dist_y;
}

static void	side_dist(t_all *all, t_raycast *raycast)
{
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (all->player.pos_x - raycast->map_x) \
											* raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = (raycast->map_x + 1.0 - all->player.pos_x) \
												* raycast->delta_dist_x;
	}
	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (all->player.pos_y - raycast->map_y) \
												* raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = (raycast->map_y + 1.0 - all->player.pos_y) \
											* raycast->delta_dist_y;
	}
}

static void	where(t_raycast *raycast)
{
	raycast->line_height = (int)(SCREEN_HEIGHT / raycast->perp_wall_dist);
	raycast->draw_start = -raycast->line_height / 2 + SCREEN_HEIGHT / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->line_height / 2 + SCREEN_HEIGHT / 2;
	if (raycast->draw_end >= SCREEN_HEIGHT)
		raycast->draw_end = SCREEN_HEIGHT - 1;
}

static void	draw_ceiling_floor(t_all *all, t_raycast *raycast, int x)
{
	int	draw_start;
	int	draw_end;

	draw_start = 0;
	draw_end = raycast->draw_start;
	while (draw_start < draw_end)
	{
		my_mlx_pixel_put(&all->img, x, draw_start, all->map.ceilling_color);
		draw_start++;
	}
	draw_start = raycast->draw_end;
	draw_end = SCREEN_HEIGHT;
	while (draw_start < draw_end)
	{
		my_mlx_pixel_put(&all->img, x, draw_start, all->map.floor_color);
		draw_start++;
	}
}

void	draw_screen(t_all *all)
{
	int			x;
	t_raycast	*raycast;

	x = -1;
	raycast = xmalloc(sizeof(t_raycast));
	while (++x < SCREEN_WIDTH)
	{
		init_raycast(x, all, raycast);
		side_dist(all, raycast);
		dda_algorithm(all, raycast);
		where(raycast);
		draw_ceiling_floor(all, raycast, x);
		draw_wall(all, raycast, x);
	}
	free(raycast);
}
