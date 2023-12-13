/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:24:05 by edupless          #+#    #+#             */
/*   Updated: 2023/08/14 13:25:29 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, const char *n)
{
	int	i;
	int	j;

	i = 0;
	if (n[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == n[j])
		{
			if (n[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}
