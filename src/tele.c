# include "../include/cub.h"

void print_portail_pos(t_map_data *data) 
{
printf("My float number: %.2f\n", data->portail_pos[1][1]);
printf("My float number: %.2f\n", data->portail_pos[1][2]);
}
void	ft_fill_portail(t_map_data *data, char *file_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			write(1,"i",1);
			
			if (data->map[i][j] == 'D')
			{
				
				data->portail_pos[1][1] = j;
				data->portail_pos[1][2] = i;
			}
			j++;
		}
		j = 0;
		i++;
	}

print_portail_pos(data); 
}

// static void	check_portail(t_vector_d *player_pos, double new_pos_x,
// 		double new_pos_y, char **map)
// {
// 	if (map[(int)new_pos_x][(int)player_pos->y] != '1')
// 		player_pos->x = new_pos_x;
// 	if (map[(int)player_pos->x][(int)new_pos_y] != '1')
// 		player_pos->y = new_pos_y;
// }