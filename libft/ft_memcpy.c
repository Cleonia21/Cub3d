/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:42:35 by celys             #+#    #+#             */
/*   Updated: 2021/11/07 16:42:35 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	size_t			k;

	k = 0;
	p = (unsigned char *)dest;
	if (!(dest) && !(src))
		return (NULL);
	while (k != n)
	{
		p[k] = ((unsigned char *)src)[k];
		k++;
	}
	return (p);
}
