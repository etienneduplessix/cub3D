/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:25:31 by edupless          #+#    #+#             */
/*   Updated: 2023/08/14 13:27:28 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	ptr = (char *)malloc(sizeof(char) * (len) + 1);
	if (!(ptr))
		return (NULL);
	while (str[i] && i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
