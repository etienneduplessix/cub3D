

# include "../../include/cub.h"

static void	hook(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		update_player_pos(&game->player, MLX_KEY_W);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		update_player_pos(&game->player, MLX_KEY_S);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		update_player_pos(&game->player, MLX_KEY_A);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		update_player_pos(&game->player, MLX_KEY_D);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(&game->player, -0.2);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(&game->player, 0.2);
	calculate_rays(game);
}

void	free_map_data(t_map_data *data)
{
	free(data->west_txt);
	free(data->south_txt);
	free(data->east_txt);
	free(data->north_txt);
	ft_free_arr((void **)data->map);
}

void	ft_free_texture(t_map_data *data)
{
	free(data->north_txt);
	free(data->east_txt);
	free(data->south_txt);
	free(data->west_txt);
}

void help_mapp(int ac, char **av)
{
	char		*map_path;
	t_mapInfo	*map_info;

	map_path = "./map.cub";
	map_info = NULL;
	if (argc > 1)
		map_path = argv[1];
	map_info = get_map(map_path);
	if (!map_info)
		return (1);
	map_info_free(map_info);	
}
int	main(int ac, char **av)
{
	t_game	game;


	help_mapp(ac,av);
	load_textures(game.textures_pxls, &game.data);
	game.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d", false);
	if (!game.mlx)
	{
		free_map_data(&game.data);
		return (1);
	}
	game.img = mlx_new_image(game.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game.img)
	{
		mlx_terminate(game.mlx);
		free_map_data(&game.data);
		return (1);
	}
	mlx_image_to_window(game.mlx, game.img, 0, 0);
	mlx_set_cursor_mode(game.mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(game.mlx, &hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_map_data(&game.data);
	return (0);
}
