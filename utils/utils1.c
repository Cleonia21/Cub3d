/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ChelseyLeonia <ChelseyLeonia@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:29:20 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/18 12:31:06 by ChelseyLeon      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/cub3d.h"

int	free_2d_int(int **p, size_t size)
{
	size_t	i;

	if (p == NULL)
		return (ERROR);
	i = 0;
	while (i < size)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (SUCCESS);
}

int	free_2d_char(char **p)
{
	size_t	i;

	if (p == NULL)
		return (ERROR);
	i = 0;
	while (p[i] != NULL)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (SUCCESS);
}

char	*my_strjoin(char *s1, char *s2, char *s3)
{
	char	*p;
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	p = ft_strjoin(tmp, s3);
	free(tmp);
	return (p);
}

int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	image_load(t_all *all, t_data *data, char	*path)
{
	int		img_width;
	int		img_height;

	data->img = mlx_xpm_file_to_image(all->mlx, path, &img_width, &img_height);
	if (data->img == NULL)
	{
		write(2, "Texture error!\n", 16);
		exit(1);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}
