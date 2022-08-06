/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ChelseyLeonia <ChelseyLeonia@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 05:13:42 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/15 05:13:43 by ChelseyLeon      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_file.h"

static void	initialize_map(t_map *map)
{
	map->ea_texture = NULL;
	map->map = NULL;
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->we_texture = NULL;
}

static int	check_for_file_permission(char *file_name)
{
	char	*permission;
	int		counter;

	permission = ".cub";
	counter = 0;
	while (*file_name)
	{
		if (*file_name != permission[counter])
			counter = 0;
		if (*file_name == permission[counter])
			counter++;
		file_name++;
	}
	if (counter == 4)
		return (SUCCESS);
	return (ERROR);
}

int	cub_file(t_map *map, t_player *player, char *file_name)
{
	int	fd;

	initialize_map(map);
	if (check_for_file_permission(file_name) == ERROR)
		return (print_return(ERROR, "File permission is invalid"));
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (print_return(ERROR, "File open error"));
	if (read_map_param(map, fd) == ERROR)
		return (print_return(ERROR, "Map param in file error"));
	if (read_map(map, player, fd) == ERROR)
		return (print_return(ERROR, "Map field error"));
	return (SUCCESS);
}
