/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cleonia <1-d_x_d-1@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:56:09 by celys             #+#    #+#             */
/*   Updated: 2022/02/20 14:40:27 by Cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../mandatory/cub3d.h"

//screenshot
void			screenshot(t_all *all);
int				**create_color_map(t_data *img);
int				search_in_array(int *array, int search);
int				*add_to_dict(int *array, int number);
int				*create_dictionary(int **array);

//fog
void			fog(t_all *all);
int				fog_init(t_all *all);

//hook
int				loop_hook(t_all *all);
int				key_release(int key, t_all *all);
int				mouse_hook(int x, int y, t_all *all);

//sprites
void			draw_sprites(t_all *all);
void			sprites_init(t_all *all);
void			light_on_off(t_all *all);

//minimap
void			draw_minimap(t_all *all);

#endif
