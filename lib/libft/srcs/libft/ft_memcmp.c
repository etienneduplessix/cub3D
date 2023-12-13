/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:08:39 by edupless          #+#    #+#             */
/*   Updated: 2023/01/19 11:52:32 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *) ptr1;
	s2 = (unsigned char *) ptr2;
	while (i < n)
	{
		if (((unsigned char *)ptr1)[i] != ((unsigned char *)ptr2)[i])
			return ((int)(s1[i] - s2[i]));
		i++;
	}
	return (0);
}
