/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:44:43 by celys             #+#    #+#             */
/*   Updated: 2021/11/17 05:22:59 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	iter;
	char			*p1;
	char			*p2;

	iter = 0;
	p1 = s1;
	p2 = s2;
	while (*(unsigned char *)p1 == *(unsigned char *)p2 && iter < n)
	{
		if (*p1 == '\0' || *p2 == '\0')
			return (0);
		iter++;
		p1++;
		p2++;
	}
	if (iter != n)
		return (*(unsigned char *)p1 - *(unsigned char *)p2);
	return (0);
}
