/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ChelseyLeonia <ChelseyLeonia@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:58:43 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/15 20:58:44 by ChelseyLeon      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw(t_all *all, t_raycast *raycast, int x, int tex_x)
{
	int		y;
	int		num_texture;
	double	tex_pos;
	double	step;
	int		tex_y;

	step = TEX_WIDTH / raycast->line_height;
	tex_pos = (raycast->draw_start - SCREEN_HEIGHT / 2 + \
						raycast->line_height / 2) * step;
	y = raycast->draw_start;
	while (y < raycast->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		num_texture = raycast->side * (raycast->step_y + 2) + \
						(!raycast->side) * (raycast->step_x + 1);
		my_mlx_pixel_put
		(
			&all->img, x, y, \
			my_mlx_pixel_get(&all->wall[num_texture], tex_x, tex_y)
		);
		y++;
	}
}

void	draw_wall(t_all *all, t_raycast *raycast, int x)
{
	int		tex_x;
	double	wall_x;

	if (raycast->side == 0)
		wall_x = all->player.pos_y + \
					(double)raycast->perp_wall_dist * raycast->ray_dir_y;
	else
		wall_x = all->player.pos_x + \
					(double)raycast->perp_wall_dist * raycast->ray_dir_x;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)(TEX_WIDTH));
	if (raycast->side == 0 && raycast->ray_dir_x > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if (raycast->side == 1 && raycast->ray_dir_y < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	draw(all, raycast, x, tex_x);
}
