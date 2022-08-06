/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:43:56 by celys             #+#    #+#             */
/*   Updated: 2021/11/16 01:06:12 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (p == NULL)
		return (NULL);
	if (s1)
	{
		j = -1;
		while (s1[++j] != '\0')
			p[i++] = s1[j];
	}
	if (s2)
	{
		j = -1;
		while (s2[++j] != '\0')
			p[i++] = s2[j];
	}
	p[i] = '\0';
	return (p);
}
