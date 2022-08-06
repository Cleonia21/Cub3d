/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:41:43 by celys             #+#    #+#             */
/*   Updated: 2021/11/07 16:42:06 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(int n)
{
	unsigned int	number;
	int				count;

	count = 0;
	number = n;
	if (n < 0)
	{
		count++;
		number = -n;
	}
	else if (n == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	number;
	int				count_bytes;
	char			*p;

	count_bytes = ft_len_int(n);
	p = malloc(sizeof(char) * (count_bytes + 1));
	if (p == NULL)
		return (NULL);
	number = n;
	p[count_bytes] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		number = -n;
	}
	else if (n == 0)
		p[0] = '0';
	while (number > 0)
	{
		count_bytes--;
		p[count_bytes] = number % 10 + '0';
		number /= 10;
	}
	return (p);
}
