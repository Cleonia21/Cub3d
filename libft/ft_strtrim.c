/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:45:10 by celys             #+#    #+#             */
/*   Updated: 2021/11/07 16:45:17 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	char		*p;
	int			i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	p = (char *) malloc(sizeof(char) * (len + 2));
	if (p == NULL)
		return (NULL);
	i = 0;
	len++;
	while (len > 0)
	{
		len--;
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
