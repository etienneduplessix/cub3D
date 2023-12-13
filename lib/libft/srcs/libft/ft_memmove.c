/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:25:42 by edupless          #+#    #+#             */
/*   Updated: 2023/08/14 13:28:55 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*sc = (const unsigned char *)src;

	i = 0;
	dst = (unsigned char *)dest;
	if (dest > src)
	{
		while (size--)
			dst[size] = sc[size];
	}
	if (dest < src)
	{
		while (size--)
		{
			dst[i] = sc[i];
			i++;
		}
	}
	return (dest);
}
