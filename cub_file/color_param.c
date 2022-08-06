/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ChelseyLeonia <ChelseyLeonia@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 05:34:51 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/16 21:14:05 by ChelseyLeon      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_file.h"

int	free_color_param_mas(char ***param_mas, int retval)
{
	int	i;

	i = -1;
	while (param_mas[0][++i])
		free (param_mas[0][i]);
	free (param_mas[0]);
	return (retval);
}

int	write_color_param(t_map *map, char *param, char key)
{
	char	**param_mas;
	int		r;
	int		g;
	int		b;

	param_mas = ft_split(param, ',');
	if (!param_mas)
		return (ERROR);
	r = ft_atoi(param_mas[0]);
	g = ft_atoi(param_mas[1]);
	b = ft_atoi(param_mas[2]);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
	{
		free_2d_char(param_mas);
		return (ERROR);
	}
	if (key == 'F')
		map->floor_color = create_trgb(0, r, g, b);
	if (key == 'C')
		map->ceilling_color = create_trgb(0, r, g, b);
	return (free_color_param_mas(&param_mas, SUCCESS));
}

int	check_color_num_for_valid(char **str)
{
	int	len;
	int	null_flag;

	null_flag = FALSE;
	while (**str == '0')
	{
		null_flag = TRUE;
		(*str)++;
	}
	len = 0;
	while (ft_isdigit(**str))
	{
		(*str)++;
		len++;
	}
	if ((len < 1 || len > 3) && null_flag == FALSE)
		return (ERROR);
	return (SUCCESS);
}

int	check_color_param(char *param)
{
	param = skip_space(param);
	if (check_color_num_for_valid(&param) == ERROR)
		return (ERROR);
	param = skip_space(param);
	if (*param != ',')
		return (ERROR);
	param = skip_space(++param);
	if (check_color_num_for_valid(&param) == ERROR)
		return (ERROR);
	param = skip_space(param);
	if (*param != ',')
		return (ERROR);
	param = skip_space(++param);
	if (check_color_num_for_valid(&param) == ERROR)
		return (ERROR);
	param = skip_space(param);
	if (*param != '\0')
		return (ERROR);
	return (SUCCESS);
}
