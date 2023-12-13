/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:39:19 by edupless          #+#    #+#             */
/*   Updated: 2023/08/14 13:26:35 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (*str)
	{
		if (*str != c && m == 0)
		{
			m = 1;
			i++;
		}
		else if (*str == c)
			m = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int d)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((d - start + 1) * sizeof(char));
	while (start < d)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !(split))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
