/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:43:46 by celys             #+#    #+#             */
/*   Updated: 2021/11/13 05:01:53 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
		{
			p = (char *) s;
			return (p);
		}
		s++;
	}
	if (c == '\0')
	{
		p = (char *) s;
		return (p);
	}
	return (NULL);
}
