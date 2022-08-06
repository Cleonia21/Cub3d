/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cleonia <1-d_x_d-1@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:16:40 by celys             #+#    #+#             */
/*   Updated: 2022/02/20 14:14:37 by Cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include <limits.h>
# include "cub3d_structs.h"

# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DOWAN			125
# define KEY_W				13
# define KEY_S				1
# define KEY_D				2
# define KEY_A				0
# define KEY_ESC			53
# define KEY_SPACE			49
# define KEY_ENTER			36
# define KEY_FN_F12			111

# define CEL_SIZE 6
# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 600
# define TEX_WIDTH 64.
# define TEX_HEIGHT 64.

# define ROTATE_SPEED 0.3
# define MOVE_SPEED 0.5

# define BARREL_WHOLE "textures/barrel_whole.xpm"
# define BARREL_RUINED "textures/barrel_ruined.xpm"
# define ELLOW_LIGHT "textures/ellowlight.xpm"
# define RED_LIGHT "textures/redlight.xpm"
# define BLACK_LIGHT "textures/blacklight.xpm"

enum	e_retvals
{
	ERROR = 1,
	SUCCESS = 0,
	TRUE = 1,
	FALSE = 0
};

enum	e_textures_name
{
	BARREL = 1,
	LIGHT = 2
};

void			cub_free(t_all *all);
void			mlx_destroy(t_all *all);

//utils0
void			replace(double *x, double x_new, double *y, double y_new);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			printf_array_int(int *arr, int size);
void			printf_array(char **arr);
int				print_return(int retval, char *print_message);

//utils1.c
void			image_load(t_all *all, t_data *data, char	*path);
char			*my_strjoin(char *s1, char *s2, char *s3);
int				my_mlx_pixel_get(t_data *data, int x, int y);
int				free_2d_int(int **p, size_t size);
int				free_2d_char(char **p);

//utils2
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);
int				create_trgb(int t, int r, int g, int b);

//utils3
void			init_raycast(int x, t_all *all, t_raycast *raycast);
int				len_int(int *array);
int				ft_itoa_base_count(unsigned long int nb, unsigned int base);
char			*ft_itoa_base(unsigned long int nb, unsigned int base);
void			*xmalloc(size_t size);

//map functions
int				cub_file(t_map *map, t_player *player, char *file_name);
int				checking_map_for_closure(char **map);

//motion
void			move_straight(int key, t_all *all);
void			move_side(int key, t_all *all);
void			rotate(int key, t_all *all, double rotSpeed);

//hook
int				key_press(int key, t_all *all);
int				destroy(t_all *all);

void			draw_wall(t_all *all, t_raycast *raycast, int x);
void			draw_screen(t_all *all);

#endif
