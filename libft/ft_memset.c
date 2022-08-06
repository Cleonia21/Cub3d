/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:42:45 by celys             #+#    #+#             */
/*   Updated: 2021/11/07 16:42:45 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			k;

	k = 0;
	p = (unsigned char *) b;
	while (k != len)
	{
		p[k] = (unsigned char)c;
		k++;
	}
	return (b);
}
