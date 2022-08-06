/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:44:48 by celys             #+#    #+#             */
/*   Updated: 2021/11/07 16:45:07 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	k;
	size_t	l;
	char	*buf;

	k = 0;
	buf = (char *) big;
	if (ft_strlen(little) == 0)
		return (buf);
	while (k < len && big[k] != '\0')
	{
		l = 0;
		if (big[k] == little[l])
		{
			while (big[k + l] == little[l] && little[l] != '\0' \
					&& (k + l) < len)
				l++;
			if (l == ft_strlen(little))
				return (&buf[k]);
		}
		k++;
	}
	return (NULL);
}
