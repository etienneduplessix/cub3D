/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:34:43 by edupless          #+#    #+#             */
/*   Updated: 2023/01/23 15:38:10 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	t;

	t = 0;
	a = ft_strlen(dst);
	b = ft_strlen(src);
	if (size < a + 1)
	{
		return (b + size);
	}
	while (a + t + 1 < size && src[t] != '\0')
	{
		dst[a + t] = src[t];
		t++;
	}
	dst[a + t] = '\0';
	return (a + b);
}
