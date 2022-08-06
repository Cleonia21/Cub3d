/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:42:30 by celys             #+#    #+#             */
/*   Updated: 2021/11/07 16:42:32 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			k;

	a = (unsigned char *) arr1;
	b = (unsigned char *) arr2;
	k = 0;
	while (k < n)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
		k++;
	}
	return (0);
}
