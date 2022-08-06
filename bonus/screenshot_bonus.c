/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:42:25 by celys             #+#    #+#             */
/*   Updated: 2022/02/18 10:40:59 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#define SCREENSHOT_FOLDER "bonus/screenshot/screenshot"

static void	print_pixels(FILE *file, int *dict, int **map)
{
	int	x;
	int	y;

	y = -1;
	fprintf(file, "/* pixels */\n");
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		fprintf(file, "\"");
		while (++x < SCREEN_WIDTH)
		{
			fprintf(file, "%c", search_in_array(dict, map[y][x]) + 35);
		}
		fprintf(file, "\",\n");
	}
}

static void	create_file(FILE *file, int *dict, int **map)
{
	int		i;
	char	*color;

	fprintf(file, "\"%d %d %d %d\",\n", SCREEN_WIDTH, \
					SCREEN_HEIGHT, len_int(dict), 1);
	i = -1;
	while (++i < len_int(dict))
	{
		color = ft_itoa_base(dict[i], 16);
		fprintf(file, "\"%c c #%s\",\n", i + 35, color);
		free(color);
	}
	print_pixels(file, dict, map);
}

static void	shot(t_all *all)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
			my_mlx_pixel_put(&all->img, x, y, 0x4d4a4a);
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
}

static FILE	*open_file(void)
{
	static int	num = 0;
	char		*num_shots;
	char		*name_screenshot;
	FILE		*file;

	num_shots = ft_itoa(num);
	name_screenshot = my_strjoin(SCREENSHOT_FOLDER, num_shots, ".xpm");
	file = fopen(name_screenshot, "w");
	if (file == NULL)
	{
		printf("SCREENSHOT_FOLDER not found!");
		exit(1);
	}
	num++;
	free(num_shots);
	free(name_screenshot);
	return (file);
}

void	screenshot(t_all *all)
{
	int			**color_map;
	int			*dict;

	color_map = create_color_map(&all->img);
	dict = create_dictionary(color_map);
	create_file(open_file(), dict, color_map);
	shot(all);
	free_2d_int(color_map, SCREEN_HEIGHT);
	free(dict);
}
