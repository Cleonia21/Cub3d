/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 05:03:44 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/17 13:50:06 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_file.h"

static int	write_file_path(char **path, char *str)
{
	int	len;
	int	i;

	str += 2;
	while (*str == ' ')
		str++;
	if (*str == '\n')
		return (ERROR);
	len = ft_strlen(str) + 1;
	*path = (char *)xmalloc(sizeof(char) * len);
	if (*path == NULL)
		return (ERROR);
	i = -1;
	while (str[++i] != '\0' && str[i] != ' ')
		path[0][i] = str[i];
	path[0][i] = '\0';
	str = skip_space(str + i);
	if (*str != '\0')
		return (ERROR);
	return (SUCCESS);
}

static void	ft_change_sumbols_in_str(char *change_str, char *change_sumbols,
									char replacement_char)
{
	int	i;

	i = 0;
	while (change_str && *change_str)
	{
		while (change_sumbols[i] != '\0')
		{
			if (change_sumbols[i] == *change_str)
				*change_str = replacement_char;
			i++;
		}
		change_str++;
	}
}

static int	write_map_param(t_map *map, char *param)
{
	ft_change_sumbols_in_str(param, "\t", ' ');
	param = skip_space(param);
	if ((*param == 'F' || *param == 'C')
		&& check_color_param(param + 1) == SUCCESS
		&& write_color_param(map, param + 1, *param) == SUCCESS)
		return (SUCCESS);
	else if (param[0] == 'N' && param[1] == 'O'
		&& write_file_path(&map->no_texture, param) == SUCCESS)
		return (SUCCESS);
	else if (param[0] == 'S' && param[1] == 'O'
		&& write_file_path(&map->so_texture, param) == SUCCESS)
		return (SUCCESS);
	else if (param[0] == 'W' && param[1] == 'E'
		&& write_file_path(&map->we_texture, param) == SUCCESS)
		return (SUCCESS);
	else if (param[0] == 'E' && param[1] == 'A'
		&& write_file_path(&map->ea_texture, param) == SUCCESS)
		return (SUCCESS);
	return (ERROR);
}

int	read_map_param(t_map *map, int fd)
{
	char	*line;
	int		retval;
	int		reads_param_num;

	reads_param_num = 0;
	while (TRUE)
	{
		retval = get_next_line(fd, &line);
		if (retval == -1 || !line)
			return (free_data(line, ERROR));
		if (str_empty(line) == FALSE)
		{
			reads_param_num++;
			if (write_map_param(map, line) == ERROR)
				return (free_data(line, ERROR));
		}
		free (line);
		if (retval == 0 || reads_param_num == 6)
			break ;
	}
	if (reads_param_num != 6)
		return (ERROR);
	return (SUCCESS);
}
