/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_viewer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:49:30 by celys             #+#    #+#             */
/*   Updated: 2022/02/17 12:21:17 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <stdio.h>
#	include "../mlx/mlx.h"
#	include <unistd.h>
#	include <stdlib.h>

typedef struct s_all
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}	t_viewer;

int	key_press(int key, t_viewer *xpm)
{
	if (key == 53)
	{
		mlx_destroy_image(xpm->mlx, xpm->img);
		exit(0);
	}
	return (0);
}

void	image_load(t_viewer *xpm, char	*path)
{
	xpm->img = mlx_xpm_file_to_image(xpm->mlx, path, &xpm->width, &xpm->height);
	if (xpm->img == NULL)
	{
		write(2, "Texture not found!\n", 20);
		exit(1);
	}
	xpm->addr = mlx_get_data_addr(xpm->img, &xpm->bits_per_pixel, \
										&xpm->line_length, &xpm->endian);
}

void	my_mlx_pixel_put(t_viewer *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	destroy(t_viewer *xpm)
{
	mlx_destroy_image(xpm->mlx, xpm->img);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_viewer	xpm;

	if (argc != 2)
	{
		write(2, "ERROR! NEED PATH TO FILE!", 26);
		return (1);
	}
	xpm.mlx = mlx_init();
	image_load(&xpm, argv[1]);
	xpm.win = mlx_new_window(xpm.mlx, xpm.width, xpm.height, "XPM_VIEWER");
	mlx_put_image_to_window(xpm.mlx, xpm.win, xpm.img, 0, 0);
	mlx_hook(xpm.win, 2, 1L << 2, key_press, (void *)&xpm);
	mlx_hook(xpm.win, 17, 0L, destroy, (void *)&xpm);
	mlx_loop(xpm.mlx);
	return (0);
}
