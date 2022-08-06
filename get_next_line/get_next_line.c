/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ChelseyLeonia <ChelseyLeonia@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:35:05 by ChelseyLeon       #+#    #+#             */
/*   Updated: 2022/02/16 21:35:07 by ChelseyLeon      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strjoin(const char **line, const char *static_line)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	new_str = (char *)malloc(gnl_strlen(*line) + gnl_strlen(static_line) + 1);
	if (new_str == NULL)
		return (-1);
	while (line[0][i] != '\0')
	{
		new_str[i] = line[0][i];
		i++;
	}
	j = 0;
	while (static_line[j] != '\0' && static_line[j] != '\n')
	{
		new_str[i] = static_line[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	free ((char *)*line);
	*line = new_str;
	return (1);
}

int	gnl_tail_cutting(char **str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 1;
	while (str[0][i - 1] != '\n')
		i++;
	tmp = (char *)gnl_calloc(BUFFER_SIZE + 1, 1);
	if (tmp == NULL)
		return (gnl_free(str, -1));
	j = 0;
	while (str[0][i] != '\0')
	{
		tmp[j] = str[0][i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	free (*str);
	*str = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*static_line;
	int			sumbol_read;

	if (fd < 0 || line == 0 || fd > 100)
		return (-1);
	sumbol_read = 1;
	*line = (char *)gnl_calloc(sizeof(char), 1);
	if (static_line == NULL)
		static_line = (char *)gnl_calloc(BUFFER_SIZE + 1, 1);
	while (static_line != NULL && *line != NULL && sumbol_read != 0)
	{
		if (gnl_strjoin((const char **)line, static_line) != -1)
			if (gnl_strchr(static_line, '\n'))
				return (gnl_tail_cutting(&static_line));
		sumbol_read = read(fd, static_line, BUFFER_SIZE);
		if (sumbol_read < 0)
			return (gnl_free(&static_line, -1));
		static_line[sumbol_read] = '\0';
	}
	if (sumbol_read == 0)
		return (gnl_free(&static_line, 0));
	return (-1);
}
