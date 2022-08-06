/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map_for_closure.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ChelseyLeonia <ChelseyLeonia@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 05:02:37 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/15 05:03:27 by ChelseyLeon      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_file.h"

int	checking_around_space(char **map, int i, int j)
{
	if (map[i][j + 1] == '0')
		return (ERROR);
	if (map[i + 1] != NULL
		&& (map[i + 1][j] == '0'
		|| map[i + 1][j + 1] == '0'))
		return (ERROR);
	if (i != 0 && (map[i - 1][j] == '0' || map[i - 1][j + 1] == '0'))
		return (ERROR);
	if (j != 0 && map[i][j - 1] == '0')
		return (ERROR);
	if (i != 0 && j != 0 && (map[i - 1][j - 1] == '0'))
		return (ERROR);
	if (j != 0 && map[i + 1] != NULL && map[i + 1][j - 1] == '0')
		return (ERROR);
	return (SUCCESS);
}

int	check_first_line(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	check_first_column(char **map)
{
	int	j;

	j = 0;
	while (map[j])
	{
		if (map[j][0] != '1' && map[j][0] != ' ')
			return (ERROR);
		j++;
	}
	return (SUCCESS);
}

int	check_second_line(char **map, int j)
{
	int	i;

	i = 0;
	while (map[j][i] != '\0')
	{
		if (map[j][i] != '1' && map[j][i] != ' ')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	checking_map_for_closure(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (check_first_line(map) == ERROR || check_first_column(map) == ERROR)
		return (ERROR);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ' && checking_around_space(map, i, j) == ERROR)
				return (ERROR);
			j++;
		}
		if (map[i][j - 1] != ' ' && map[i][j - 1] != '1')
			return (ERROR);
		i++;
	}
	if (check_second_line(map, i - 1) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
