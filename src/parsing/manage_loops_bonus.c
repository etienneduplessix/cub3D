

# include "../../include/cub.h"

int	ft_manage_west_loop(t_map_data *data, char *file_data, int i, int length)
{
	while (file_data[i] && file_data[i] != '\n')
	{
		length++;
		i++;
	}
	data->west_txt = ft_calloc(sizeof(char), length + 1);
	i -= length;
	length = 0;
	while (file_data[i] && file_data[i] != '\n')
	{
		data->west_txt[length] = file_data[i];
		i++;
		length++;
	}
	return (i);
}

int	ft_manage_north_loop(t_map_data *data, char *file_data, int i, int length)
{
	while (file_data[i] && file_data[i] != '\n')
	{
		length++;
		i++;
	}
	data->north_txt = ft_calloc(sizeof(char), length + 1);
	i -= length;
	length = 0;
	while (file_data[i] && file_data[i] != '\n')
	{
		data->north_txt[length] = file_data[i];
		i++;
		length++;
	}
	return (i);
}

int	ft_manage_south_loop(t_map_data *data, char *file_data, int i, int length)
{
	while (file_data[i] && file_data[i] != '\n')
	{
		length++;
		i++;
	}
	data->south_txt = ft_calloc(sizeof(char), length + 1);
	i -= length;
	length = 0;
	while (file_data[i] && file_data[i] != '\n')
	{
		data->south_txt[length] = file_data[i];
		i++;
		length++;
	}
	return (i);
}

int	ft_manage_east_loop(t_map_data *data, char *file_data, int i, int length)
{
	while (file_data[i] && file_data[i] != '\n')
	{
		length++;
		i++;
	}
	data->east_txt = ft_calloc(sizeof(char), length + 1);
	i -= length;
	length = 0;
	while (file_data[i] && file_data[i] != '\n')
	{
		data->east_txt[length] = file_data[i];
		i++;
		length++;
	}
	return (i);
}
