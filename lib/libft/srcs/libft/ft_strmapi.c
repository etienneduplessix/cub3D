/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:25:41 by edupless          #+#    #+#             */
/*   Updated: 2023/08/14 13:26:57 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*fr;
	size_t	len;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	fr = malloc((len + 1) * sizeof(char));
	if (fr == NULL)
		return (NULL);
	fr[len] = '\0';
	while (s[i] != '\0')
	{
		fr[i] = (*f)(i, s[i]);
		i++;
	}
	return (fr);
}
