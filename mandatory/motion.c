/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:33:17 by celys             #+#    #+#             */
/*   Updated: 2022/02/20 18:45:59 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define DISTANCE 0.3

static double	get_raise_y(t_all *all, double step_y)
{
	double	raise_y;

	raise_y = step_y + all->player.pos_y;
	if (all->player.dir_y <= 0)
	{
		if (all->map.map[(int)(all->player.pos_x)][(int)raise_y] == '1')
			raise_y = (int)raise_y + 1 + DISTANCE;
		else if (all->map.map[(int)all->player.pos_x][(int)raise_y - 1] == '1')
		{
			if (all->player.pos_y + step_y < (double)((int)raise_y) + DISTANCE)
				raise_y = (double)((int)raise_y) + DISTANCE;
		}
	}
	if (all->player.dir_y > 0)
	{
		if (all->map.map[(int)(all->player.pos_x)][(int)raise_y] == '1')
			raise_y = (int)raise_y - DISTANCE;
		else if (all->map.map[(int)all->player.pos_x][(int)raise_y + 1] == '1')
		{
			if (all->player.pos_y + step_y > (int)raise_y + 1 - DISTANCE)
				raise_y = (double)((int)raise_y) + 1 - DISTANCE;
		}
	}
	return (raise_y);
}

static double	get_raise_x(t_all *all, double step_x)
{
	double	raise_x;

	raise_x = step_x + all->player.pos_x;
	if (all->player.dir_x > 0)
	{
		if (all->map.map[(int)raise_x][(int)(all->player.pos_y)] == '1')
			raise_x = (double)((int)all->player.pos_x + 1) - DISTANCE;
		else if (all->map.map[(int)raise_x + 1][(int)all->player.pos_y] == '1')
		{
			if (raise_x > (double)((int)raise_x + 1) - DISTANCE)
				raise_x = (double)((int)raise_x + 1) - DISTANCE;
		}
	}
	if (all->player.dir_x <= 0)
	{
		if (all->map.map[(int)raise_x][(int)all->player.pos_y] == '1')
			raise_x = (double)((int)(raise_x + 1)) + DISTANCE;
		else if (all->map.map[(int)raise_x - 1][(int)all->player.pos_y] == '1')
		{
			if (raise_x < (double)((int)raise_x) + DISTANCE)
				raise_x = (double)((int)raise_x) + DISTANCE;
		}
	}
	return (raise_x);
}

void	move_straight(int key, t_all *all)
{
	double	move_speed;
	double	step_x;
	double	step_y;

	move_speed = MOVE_SPEED;
	if (key == KEY_S)
		move_speed = -move_speed;
	step_x = all->player.dir_x * move_speed;
	step_y = all->player.dir_y * move_speed;
	if (key == KEY_S)
	{
		all->player.dir_x *= -1;
		all->player.dir_y *= -1;
	}
	all->player.pos_x = get_raise_x(all, step_x);
	all->player.pos_y = get_raise_y(all, step_y);
	if (key == KEY_S)
	{
		all->player.dir_x *= -1;
		all->player.dir_y *= -1;
	}
}

void	move_side(int key, t_all *all)
{
	double	move_speed;
	double	step_x;
	double	step_y;

	move_speed = MOVE_SPEED;
	if (key == KEY_A)
		move_speed = -move_speed;
	step_x = all->player.dir_y * move_speed;
	step_y = -all->player.dir_x * move_speed;
	if (key == KEY_A)
	{
		all->player.dir_x *= -1;
		all->player.dir_y *= -1;
	}
	replace(&all->player.dir_x, all->player.dir_y, \
				&all->player.dir_y, -all->player.dir_x);
	all->player.pos_x = get_raise_x(all, step_x);
	all->player.pos_y = get_raise_y(all, step_y);
	if (key == KEY_A)
	{
		all->player.dir_x *= -1;
		all->player.dir_y *= -1;
	}
	replace(&all->player.dir_x, -all->player.dir_y, \
				&all->player.dir_y, all->player.dir_x);
}

void	rotate(int key, t_all *all, double rotSpeed)
{
	double	old_dir;
	double	old_plane;

	if (key == KEY_RIGHT)
		rotSpeed = -rotSpeed;
	old_dir = all->player.dir_x;
	all->player.dir_x = all->player.dir_x * cos(rotSpeed) - \
						all->player.dir_y * sin(rotSpeed);
	all->player.dir_y = old_dir * sin(rotSpeed) + \
						all->player.dir_y * cos(rotSpeed);
	old_plane = all -> player.plane_x;
	all -> player.plane_x = all -> player.plane_x * cos(rotSpeed) - \
							all -> player.plane_y * sin(rotSpeed);
	all -> player.plane_y = old_plane * sin(rotSpeed) \
							+ all -> player.plane_y * cos(rotSpeed);
}
