/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ChelseyLeonia <ChelseyLeonia@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 05:15:06 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/15 05:32:12 by ChelseyLeon      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_file.h"

int	checking_map_for_invalid_sumbol(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != ' ' && map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W')
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	search_player_pos_in_map(char **map, t_player *player)
{
	int	pos_num;
	int	i;
	int	j;

	pos_num = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				player->pos_x = i + 0.5;
				player->pos_y = j + 0.5;
				player->start_side = map[i][j];
				pos_num++;
				map[i][j] = '0';
			}
		}
	}
	if (pos_num != 1)
		return (ERROR);
	return (SUCCESS);
}

int	read_map(t_map *map, t_player *player, int fd)
{
	if (make_map_mas(map, fd) == ERROR
		|| checking_map_for_closure(map->map) == ERROR
		|| checking_map_for_invalid_sumbol(map->map) == ERROR
		|| search_player_pos_in_map(map->map, player) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
