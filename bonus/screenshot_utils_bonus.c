/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:43:16 by celys             #+#    #+#             */
/*   Updated: 2022/02/17 13:49:45 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	**create_color_map(t_data *img)
{
	int	i;
	int	**array;
	int	x;
	int	y;

	i = -1;
	array = xmalloc(sizeof(int *) * SCREEN_HEIGHT);
	while (++i < SCREEN_HEIGHT)
		array[i] = xmalloc(sizeof(int) * SCREEN_WIDTH);
	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
		{
			array[y][x] = my_mlx_pixel_get(img, x, y);
		}
	}
	return (array);
}

int	search_in_array(int *array, int search)
{
	int	i;

	i = -1;
	if (array == NULL)
		return (-1);
	while (array[++i] != -1)
	{
		if (search == array[i])
			return (i);
	}
	return (-1);
}

int	*add_to_dict(int *array, int number)
{
	int		*new_array;
	int		i;

	new_array = xmalloc(sizeof(int) * len_int(array) + 5);
	i = -1;
	if (array != NULL)
	{
		while (array[++i] != -1)
			new_array[i] = array[i];
	}
	else
		++i;
	new_array[i] = number;
	new_array[i + 1] = -1;
	free(array);
	return (new_array);
}

int	*create_dictionary(int **array)
{
	int	*dict;
	int	x;
	int	y;

	dict = NULL;
	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
		{
			if (search_in_array(dict, array[y][x]) == -1)
				dict = add_to_dict(dict, array[y][x]);
		}
	}
	return (dict);
}
