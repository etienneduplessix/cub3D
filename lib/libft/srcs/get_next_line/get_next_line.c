/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:14:39 by edupless          #+#    #+#             */
/*   Updated: 2023/07/17 17:27:35 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *buf, char *stock)
{
	int		ret;
	char	*temps;

	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (0);
		else if (ret == 0)
			break ;
		buf[ret] = '\0';
		if (!stock)
			stock = ft_strdup2("");
		temps = stock;
		stock = ft_strjoin2(temps, buf);
		if (!stock)
			return (NULL);
		free(temps);
		temps = NULL;
		if (ft_strchr2(buf, '\n'))
			break ;
	}
	return (stock);
}

char	*ft_select(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	result = ft_substr(line, i + 1, ft_strlen2(line) - i);
	if (!result)
		return (NULL);
	if (result[0] == '\0')
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)

{
	char		*line;
	char		*buf ;
	static char	*stock ;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, buf, stock);
	free (buf);
	buf = NULL;
	if (!line)
		return (NULL);
	stock = ft_select(line);
	return (line);
}
