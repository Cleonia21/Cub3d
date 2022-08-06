/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ChelseyLeonia <ChelseyLeonia@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:34:12 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/16 21:34:57 by ChelseyLeon      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<unistd.h>

# define BUFFER_SIZE 10

typedef struct s_list
{
	char			*static_line;
	int				fd;
	struct s_list	*next;
}					t_list;

size_t				gnl_strlen(const char *str);
void				*gnl_calloc(size_t count, size_t size);
char				*gnl_strchr(char *s, int c);
int					gnl_strjoin(const char **line, const char *static_line);
int					get_next_line(int fd, char **line);
int					gnl_tail_cutting(char **str);
int					gnl_free(char **s, int i);

#endif