/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:20:49 by celys             #+#    #+#             */
/*   Updated: 2022/02/20 17:07:11 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy(t_all *all)
{
	mlx_destroy(all);
	cub_free(all);
	exit(0);
	return (0);
}

int	key_press(int key, t_all *all)
{
	if (key == KEY_W || key == KEY_S)
		move_straight(key, all);
	if (key == KEY_A || key == KEY_D)
		move_side(key, all);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		rotate(key, all, ROTATE_SPEED);
	if (key == KEY_ESC)
		destroy(all);
	draw_screen(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	return (SUCCESS);
}
