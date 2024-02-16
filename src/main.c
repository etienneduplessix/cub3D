/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:05:39 by zabdulza          #+#    #+#             */
/*   Updated: 2024/02/15 17:07:58 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	hook(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		update_player_pos(&game->player, MLX_KEY_W, game->data.map);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		update_player_pos(&game->player, MLX_KEY_S, game->data.map);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		update_player_pos(&game->player, MLX_KEY_A, game->data.map);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		update_player_pos(&game->player, MLX_KEY_D, game ->data.map);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(&game->player, -0.2);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(&game->player, 0.2);
	mouse_rotation(game->mlx, &game->player);
	calculate_rays(game);
	draw_minimap(game);
	draw_square(game, game->player.pos.y * 5, \
	game->player.pos.x * 5, 0xFF000090);
}

int	get_array_height(void **data)
{
	int	height;

	height = 0;
	while (data[height] != NULL)
	{
		height++;
	}
	return (height);
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

int	main(int ac, char **av)
{
	t_game	game;

	if (map_parsing(ac, av, &game) == false)
		exit (0);
	load_textures(game.textures_pxls, &game.data);
	game.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", false);
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
