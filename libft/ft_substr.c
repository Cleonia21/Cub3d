/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:45:19 by celys             #+#    #+#             */
/*   Updated: 2021/11/10 01:49:01 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	size_t			count_byte;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) < start)
		count_byte = 1;
	else if (ft_strlen(s) - start >= len)
		count_byte = (len + 1) * sizeof(char);
	else
		count_byte = (ft_strlen(s) - start + 1) * sizeof(char);
	p = malloc(count_byte);
	if (p == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0' && ft_strlen(s) >= start)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
