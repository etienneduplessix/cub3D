/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etienneduplessix <etienneduplessix@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:08:32 by nroth             #+#    #+#             */
/*   Updated: 2023/12/11 15:38:54 by etiennedupl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parsing.h"

size_t	ft_arrlen(void **s)
{
	unsigned long	length;

	if (!s)
		return (0);
	length = 0;
	while ((char *) s[length] != NULL)
		length++;
	return (length);
}
void	**ft_arrappend_void(void **arr, void *to_append)
{
	void	**ret;
	int		i;

	i = 0;
	ret = malloc (sizeof (void *) * (ft_arrlen(arr) + 2));
	while (arr && arr[i])
	{
		ret[i] = arr[i];
		i++;
	}
	ret [i] = to_append;
	ret [i + 1] = NULL;
	free (arr);
	arr = ret;
	return (ret);
}
char	**ft_arrappend(char **arr, char *to_append)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc (sizeof (char *) * (ft_arrlen((void **) arr) + 2));
	while (arr && arr[i])
	{
		ret[i] = arr[i];
		i++;
	}
	ret [i] = to_append;
	ret [i + 1] = NULL;
	free (arr);
	arr = ret;
	return (ret);
}
//Functions to fill the actual map layout and check its validity
bool	is_map_line(char *map_line)
{
	while (*map_line && *map_line != '\n')
	{
		if (!ft_isdigit(*map_line) && *map_line != ' ')
			return (false);
		map_line++;
	}
	return (true);
}

bool	isvalid_firstline(char *line)
{
	if (!line)
		return (false);
	while (*line)
	{
		if (*line != '1' && *line != ' ')
			return (false);
		if (*line == ' ')
			*line = '1';
		line++;
	}
	return (true);
}

bool	isvalid_midline(char *line)
{
	while (line && *line == ' ')
		*(line++) = '1';
	if (!line || *line != '1')
		return (false);
	while (*line)
	{
		if (!line[1] && *line != '1')
			return (false);
		else if (!ft_strchr(ALLOWED_MAPCHARS, *line))
			return (false);
		line++;
	}
	return (true);
}

bool	isvalid_map(char **map, int map_width)
{
	int		i;
	int		player_found;
	char	*temp_line;

	i = 0;
	player_found = 0;
	if (isvalid_firstline(map[i--]) == false)
	{
		
		return (false);
	}
	while (map[++i])
	{
		while ((int)ft_strlen (map[i]) < map_width)
		{
			temp_line = ft_strjoin(map[i], "1");
			free(map[i]);
			map[i] = temp_line;
		}
		if (isvalid_midline(map[i]) == false)
		{
			write(1,"f",1);
			return (false);
		}
		if (ft_strchr(map[i], 'N') || ft_strchr(map[i], 'S')
			|| ft_strchr(map[i], 'E') || ft_strchr(map[i], 'W'))
			player_found++;
	}
	if (isvalid_firstline(map[i - 1]) == false || player_found != 1)
		return (false);
	return (true);
}

bool	process_map_arr(char *map_line, t_mapInfo *map_info, int map_fd)
{
	char	**map;

	map = ft_calloc(sizeof(char *), 1);
	map[0] = NULL;
	while (map_line)
	{
		map = ft_arrappend (map, ft_strtrim(map_line, "\n"));
		map_info->map_height ++;
		if ((int) ft_strlen (map_line) - 1 > map_info->map_width)
			map_info->map_width = ft_strlen (map_line) - 1;
		map_line = (free (map_line), get_next_line(map_fd));
	}
	if (isvalid_map(map, map_info->map_width) == false)
	{
		ft_arrfree((void **) map);
		return (ft_error (NULL, "Invalid Map!\n"), false);
	}
	map_info->map = map;
	return (true);
}
