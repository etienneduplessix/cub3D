/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:36:24 by edupless          #+#    #+#             */
/*   Updated: 2023/08/14 13:25:49 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t size)
{
	unsigned char	*dst;

	dst = (unsigned char *)dest;
	while (size--)
	{
		*dst = (unsigned char)value;
		dst++;
	}
	return (dest);
}
