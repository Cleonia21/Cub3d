/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:44:23 by celys             #+#    #+#             */
/*   Updated: 2021/11/07 16:44:23 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	k;

	k = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (size <= len_dst)
		return (size + len_src);
	while (src[k] != '\0' && (len_dst + k + 1) < size)
	{
		dst[len_dst + k] = src[k];
		k++;
	}
	dst[len_dst + k] = '\0';
	return (len_src + len_dst);
}
