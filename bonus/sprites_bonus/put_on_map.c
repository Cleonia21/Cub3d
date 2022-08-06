/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ChelseyLeonia <ChelseyLeonia@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:18:42 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/17 15:35:06 by ChelseyLeon      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

static int	perpendicular_walls(char **map, int i, int j)
{
	int	retval;

	retval = 0;
	if (map[i - 1][j] == '1')
		retval++;
	if (map[i + 1][j] == '1')
		retval++;
	if (map[i][j - 1] == '1')
		retval++;
	if (map[i][j + 1] == '1')
		retval++;
	if (retval == 3)
		return (BARREL);
	return (0);
}

static int	empty_lines(char **map, int i, int j)
{
	int	retval;

	retval = 0;
	if (map[i - 1][j] == '0' && map[i - 2][j] == '0' && map[i - 3][j])
		retval++;
	if (map[i + 1][j] == '0' && map[i + 2][j] == '0' && map[i + 3][j])
		retval++;
	if (map[i][j - 1] == '0' && map[i][j - 2] == '0' && map[i][j - 3] == '0')
		retval++;
	if (map[i][j + 1] == '0' && map[i][j + 2] == '0' && map[i][j + 3] == '0')
		retval++;
	if (retval == 4)
		return (LIGHT);
	return (0);
}

static void	put_sprite(t_coordinate *coordinates, t_sprites_on_map *param)
{
	coordinates[param->fact_sprites_num].texture_name = param->if_there_are;
	coordinates[param->fact_sprites_num].x = (double)param->i + 0.5;
	coordinates[param->fact_sprites_num].y = (double)param->j + 0.5;
	coordinates[param->fact_sprites_num].texture_flag = 0;
	param->if_there_are = 0;
	param->fact_sprites_num++;
}

void	put_sprites_on_map(t_all *all, t_map *map)
{
	t_sprites_on_map	param;

	param.i = -1;
	param.fact_sprites_num = 0;
	param.if_there_are = 0;
	while (map->map[++param.i])
	{
		param.j = -1;
		while (map->map[param.i][++param.j] != '\0')
		{
			if (map->map[param.i][param.j] == '0')
			{
				param.if_there_are += perpendicular_walls(map->map,
						param.i, param.j);
				param.if_there_are += empty_lines(map->map, param.i, param.j);
				if (param.if_there_are > 0)
					put_sprite(all->sprites.coordinates, &param);
				if (param.fact_sprites_num == all->sprites.num)
					return ;
			}
		}
	}
	all->sprites.num = param.fact_sprites_num;
}
