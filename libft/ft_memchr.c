/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:42:25 by celys             #+#    #+#             */
/*   Updated: 2021/11/07 16:42:27 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;
	size_t			k;

	k = 0;
	p = (unsigned char *)arr;
	ch = (unsigned char)c;
	while (k < n)
	{
		if (*p == ch)
			return (p);
		k++;
		p++;
	}
	return (NULL);
}
