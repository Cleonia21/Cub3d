/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:33:49 by celys             #+#    #+#             */
/*   Updated: 2022/02/21 19:05:24 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	side_init(t_player *player)
{
	int	flag;

	if (player->start_side == 'N' || player->start_side == 'W')
		flag = -1;
	if (player->start_side == 'S' || player->start_side == 'E')
		flag = 1;
	if (player->start_side == 'W' || player->start_side == 'E')
	{
		player->dir_x = 0;
		player->plane_y = 0;
		player->dir_y = flag * 1;
		player->plane_x = flag * 0.66;
	}
	if (player->start_side == 'N' || player->start_side == 'S')
	{
		player->plane_x = 0;
		player->dir_y = 0;
		player->dir_x = flag * 1;
		player->plane_y = flag * 0.66;
	}
}

static void	cub_init(t_all *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	all->img.img = mlx_new_image(all->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, \
									&all->img.line_length, &all->img.endian);
	side_init(&all->player);
	if (all->player.start_side == 'S' || all->player.start_side == 'N')
	{
		all->player.plane_x *= -1;
		all->player.plane_y *= -1;
	}
	all->wall = (t_data *)xmalloc(sizeof(t_data) * 4);
	image_load(all, &all->wall[0], all->map.no_texture);
	image_load(all, &all->wall[1], all->map.we_texture);
	image_load(all, &all->wall[2], all->map.so_texture);
	image_load(all, &all->wall[3], all->map.ea_texture);
}

void	cub_free(t_all *all)
{
	free(all->wall);
	free_2d_char(all->map.map);
	free(all->map.no_texture);
	free(all->map.so_texture);
	free(all->map.we_texture);
	free(all->map.ea_texture);
}

void	mlx_destroy(t_all *all)
{
	mlx_destroy_image(all->mlx, all->img.img);
	mlx_destroy_window(all->mlx, all->win);
	mlx_destroy_image(all->mlx, all->wall[0].img);
	mlx_destroy_image(all->mlx, all->wall[1].img);
	mlx_destroy_image(all->mlx, all->wall[2].img);
	mlx_destroy_image(all->mlx, all->wall[3].img);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2)
		return (print_return(ERROR, "argv error"));
	if (cub_file(&all.map, &all.player, argv[1]) != SUCCESS)
		return (ERROR);
	cub_init(&all);
	draw_screen(&all);
	mlx_put_image_to_window(all.mlx, all.win, all.img.img, 0, 0);
	mlx_hook(all.win, 2, 1L << 2, key_press, (void *)&all);
	mlx_hook(all.win, 17, 0, destroy, (void *)&all);
	mlx_loop(all.mlx);
	return (SUCCESS);
}
