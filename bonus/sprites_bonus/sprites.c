/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cleonia <1-d_x_d-1@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:13:51 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/20 15:14:18 by Cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

void	sprites_init(t_all *all)
{
	all->sprites.num = 20;
	all->sprites.z_buffer = (double *)xmalloc(sizeof(double) * SCREEN_WIDTH);
	all->sprites.coordinates = (t_coordinate *)xmalloc(sizeof(t_coordinate)
			* all->sprites.num);
	all->sprites.texture_barrel = (t_data *)xmalloc(sizeof(t_data) * 2);
	image_load(all, &all->sprites.texture_barrel[0], BARREL_WHOLE);
	image_load(all, &all->sprites.texture_barrel[1], BARREL_RUINED);
	all->sprites.texture_light = (t_data *)xmalloc(sizeof(t_data) * 3);
	image_load(all, &all->sprites.texture_light[0], ELLOW_LIGHT);
	image_load(all, &all->sprites.texture_light[1], RED_LIGHT);
	image_load(all, &all->sprites.texture_light[2], BLACK_LIGHT);
	all->sprites.coller = 0;
	all->sprites.coller_max = 89;
	all->sprites.coller_min = 0;
	all->sprites.coller_mod = 45;
	put_sprites_on_map(all, &all->map);
	all->sprites.distance = (int *)xmalloc(sizeof(int) * all->sprites.num);
	all->sprites.iterator = (int *)xmalloc(sizeof(int) * all->sprites.num);
}

static void	sort_distance(int *nums, int *itrs, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (nums[j - 1] > nums[j])
			{
				temp = nums[j - 1];
				nums[j - 1] = nums[j];
				nums[j] = temp;
				temp = itrs[j - 1];
				itrs[j - 1] = itrs[j];
				itrs[j] = temp;
			}
			j--;
		}
		i++;
	}
}

static void	draw_line(t_data *put_img,
	t_data *get_img, t_sprites_param *param, int y)
{
	int	color;

	while (y < param->draw_end_y)
	{
		param->tex_y = (((y * 2 - (SCREEN_HEIGHT - param->sprite_height))
					* 128 * TEX_HEIGHT) / param->sprite_height) / 256;
		color = 0x000000;
		if (get_img)
			color = my_mlx_pixel_get(get_img, param->tex_x, param->tex_y);
		if (color != 0x000000)
			my_mlx_pixel_put(put_img, param->draw_start_x, y, color);
		y++;
	}
}

static void	draw(t_all *all, t_sprites_param *param, int i)
{
	t_data	*picture;
	int		y;

	while (param->draw_start_x < param->draw_end_x)
	{
		picture = NULL;
		y = param->draw_start_y;
		param->tex_x = (int)(256 * (param->draw_start_x
					- (-param->sprite_width / 2 + param->sprite_screen_x))
				* TEX_WIDTH / param->sprite_width) / 256;
		if (all->sprites.coordinates[i].texture_name == BARREL)
			picture = &all->sprites.texture_barrel
			[all->sprites.coordinates[i].texture_flag];
		if (all->sprites.coordinates[i].texture_name == LIGHT)
			picture = &all->sprites.texture_light
			[all->sprites.coller / all->sprites.coller_mod];
		if (param->transform_y > 0 && param->transform_y
			< all->sprites.z_buffer[param->draw_start_x])
			draw_line(&all->img, picture, param, y);
		param->draw_start_x++;
	}
}

void	draw_sprites(t_all *all)
{
	t_sprites_param	param;
	int				i;
	int				j;

	calculation_distance(&all->sprites, &all->player);
	sort_distance(all->sprites.distance,
		all->sprites.iterator, all->sprites.num);
	all->sprites.coller++;
	if (all->sprites.coller >= all->sprites.coller_max)
		all->sprites.coller = all->sprites.coller_min;
	j = all->sprites.num;
	while (--j >= 0)
	{
		i = all->sprites.iterator[j];
		if (calculation_general_parameters(all, &param, i) == FALSE)
			continue ;
		calculation_start_end(&param);
		draw(all, &param, i);
	}
}
