/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ChelseyLeonia <ChelseyLeonia@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 05:32:20 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/17 15:37:32 by ChelseyLeon      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FILE_H
# define CUB_FILE_H

# include "../mandatory/cub3d.h"

typedef struct s_line_list
{
	char				*line;
	struct s_line_list	*next;
}	t_line_list;

typedef struct s_map_mas
{
	t_line_list	*first_line;
	t_line_list	*line;
	int			line_num;
	int			max_line_len;
}	t_map_mas;

int			write_color_param(t_map *map, char *param, char key);
int			check_color_param(char *param);
int			read_map_param(t_map *map, int fd);
int			read_map(t_map *map, t_player *player, int fd);
int			make_map_mas(t_map *struct_map, int fd);
int			write_map_list(t_map_mas *map_list, int fd);

// utils
char		*skip_space(char *str);
int			str_empty(char *str);
int			free_data(void *data, int retval);
int			free_map_list(t_map_mas *map_list, int retval);
t_map_mas	initial_map_list(void);

#endif