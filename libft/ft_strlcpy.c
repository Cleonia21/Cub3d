/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:44:28 by celys             #+#    #+#             */
/*   Updated: 2021/11/07 16:44:29 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	k;
	size_t	len;

	k = 0;
	len = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (k < (size - 1) && src[k] != '\0')
		{
			dst[k] = src[k];
			k++;
		}
		dst[k] = '\0';
	}
	while (src[len] != '\0')
		len++;
	return (len);
}
