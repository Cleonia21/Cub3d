/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:42:16 by celys             #+#    #+#             */
/*   Updated: 2021/11/07 16:42:18 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			k;
	unsigned char	*p;
	unsigned char	r;

	k = 0;
	p = (unsigned char *) dest;
	r = (unsigned char) c;
	if (!(dest) && !(src))
		return (NULL);
	while (k != n)
	{
		p[k] = ((unsigned char *)src)[k];
		if (((unsigned char *)src)[k] == r)
			return (p + k + 1);
		k++;
	}
	return (NULL);
}
