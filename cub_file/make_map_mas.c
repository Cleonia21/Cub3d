/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_mas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ChelseyLeonia <ChelseyLeonia@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 05:13:59 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/16 21:33:15 by ChelseyLeon      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_file.h"

int	get_memory_for_map_mas(t_map *struct_map, t_map_mas map_list)
{
	int	i;

	struct_map->map = (char **)ft_calloc(sizeof(char *),
			(map_list.line_num + 1));
	if (!struct_map->map)
		return (ERROR);
	struct_map->map[map_list.line_num] = NULL;
	i = -1;
	while (++i < map_list.line_num)
	{
		struct_map->map[i] = (char *)ft_calloc(sizeof(char),
				(map_list.max_line_len + 1));
		if (!struct_map->map[i])
		{
			while (--i >= 0)
				free (struct_map->map[i]);
			free (struct_map->map);
			struct_map->map = NULL;
		}
		struct_map->map[i][map_list.max_line_len] = '\0';
	}
	return (SUCCESS);
}

int	write_list_in_ccmas(t_map *struct_map, t_map_mas map_list)
{
	int	i;
	int	j;

	if (get_memory_for_map_mas(struct_map, map_list) == ERROR)
		return (ERROR);
	i = -1;
	while (++i < map_list.line_num)
	{
		j = -1;
		while (++j < (int)ft_strlen(map_list.line->line))
			struct_map->map[i][j] = map_list.line->line[j];
		while (j < map_list.max_line_len)
			struct_map->map[i][j++] = ' ';
		map_list.line = map_list.line->next;
	}
	struct_map->width = map_list.line_num;
	struct_map->height = map_list.max_line_len;
	return (SUCCESS);
}

int	make_map_mas(t_map *struct_map, int fd)
{
	t_map_mas	map_list;

	map_list = initial_map_list();
	if (map_list.line_num == -1)
		return (ERROR);
	if (write_map_list(&map_list, fd) == ERROR)
		return (free_map_list(&map_list, ERROR));
	map_list.line = map_list.first_line;
	if (write_list_in_ccmas(struct_map, map_list) == ERROR)
		return (free_map_list(&map_list, ERROR));
	free_map_list(&map_list, 1);
	return (SUCCESS);
}
