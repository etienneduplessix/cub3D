/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:05:21 by zabdulza          #+#    #+#             */
/*   Updated: 2024/02/07 15:30:24 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	ft_init_data(t_map_data *data)
{
	data->north_txt = NULL;
	data->south_txt = NULL;
	data->east_txt = NULL;
	data->west_txt = NULL;
	data->map = NULL;
	data->floor_color[0] = 0;
	data->floor_color[1] = 0;
	data->floor_color[2] = 0;
	data->ceil_color[0] = 0;
	data->ceil_color[1] = 0;
	data->ceil_color[2] = 0;
	data->map_index = 0;
	data->map_max_x = 0;
	data->map_max_y = 0;
}

int	ft_manage_west(t_map_data *data, char *file_data, int i, t_parse *parse)
{
	int	length;

	length = 0;
	if (i == 0)
		i += 2;
	else
		i += 3;
	while (file_data[i] && file_data[i] == ' ')
		i++;
	if (parse->valid_west == 1)
		return (-1);
	i = ft_manage_west_loop(data, file_data, i, length);
	parse->valid_west = 1;
	return (i - 1);
}

int	ft_manage_north(t_map_data *data, char *file_data, int i, t_parse *parse)
{
	int	length;

	length = 0;
	if (i == 0)
		i += 2;
	else
		i += 3;
	while (file_data[i] && file_data[i] == ' ')
		i++;
	if (parse->valid_north == 1)
		return (-1);
	i = ft_manage_north_loop(data, file_data, i, length);
	parse->valid_north = 1;
	return (i - 1);
}

int	ft_manage_south(t_map_data *data, char *file_data, int i, t_parse *parse)
{
	int	length;

	length = 0;
	if (i == 0)
		i += 2;
	else
		i += 3;
	while (file_data[i] && file_data[i] == ' ')
		i++;
	if (parse->valid_south == 1)
		return (-1);
	i = ft_manage_south_loop(data, file_data, i, length);
	parse->valid_south = 1;
	return (i - 1);
}

int	ft_manage_east(t_map_data *data, char *file_data, int i, t_parse *parse)
{
	int	length;

	length = 0;
	if (i == 0)
		i += 2;
	else
		i += 3;
	while (file_data[i] && file_data[i] == ' ')
		i++;
	if (parse->valid_east == 1)
		return (-1);
	i = ft_manage_east_loop(data, file_data, i, length);
	parse->valid_east = 1;
	return (i - 1);
}
