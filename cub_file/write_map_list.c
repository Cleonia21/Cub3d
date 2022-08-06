/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 05:34:36 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/17 13:50:12 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_file.h"

static int	check_for_end(int fd)
{
	char	*line;
	int		retval;

	retval = 1;
	while (retval)
	{
		retval = get_next_line(fd, &line);
		if (retval == -1 || !line)
			return (ERROR);
		if (str_empty(line) == FALSE)
			return (free_data(line, ERROR));
		free (line);
	}
	return (SUCCESS);
}

static int	write_line_in_map_list(t_map_mas *map_list, char *line)
{
	map_list->line_num++;
	if (map_list->max_line_len < (int)ft_strlen(line))
		map_list->max_line_len = ft_strlen(line);
	map_list->line->line = line;
	map_list->line->next = (t_line_list *)xmalloc(sizeof(t_line_list));
	if (!map_list->line->next)
		return (free_map_list(map_list, ERROR));
	map_list->line = map_list->line->next;
	map_list->line->line = NULL;
	map_list->line->next = NULL;
	return (SUCCESS);
}

int	write_map_list(t_map_mas *map_list, int fd)
{
	char	*line;
	int		retval;

	retval = 1;
	while (retval)
	{
		retval = get_next_line(fd, &line);
		if (retval == -1 || !line)
			return (free_data(line, ERROR));
		if (str_empty(line) == TRUE)
		{
			free (line);
			if (map_list->line_num != 0)
				break ;
			continue ;
		}
		if (write_line_in_map_list(map_list, line) == ERROR)
			return (ERROR);
	}
	if (map_list->line_num == 0 || (retval != 0 && check_for_end(fd) == ERROR))
		return (ERROR);
	return (SUCCESS);
}
