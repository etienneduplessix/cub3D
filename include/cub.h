/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:03:44 by zabdulza          #+#    #+#             */
/*   Updated: 2024/02/15 16:48:08 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "game_struct.h"
# include "constants.h"
# include "parsing.h"
# include "matrix.h"
# include "vector.h"
# include <stdlib.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <memory.h>
# include "../lib/libft/includes/libft.h"
# include "../lib/libft/includes/get_next_line.h"
# include "../lib/libft/includes/ft_printf.h"

void		draw_minimap(t_game *game);
void		draw_square(t_game *game, int x, int y, int color);
int			load_textures(uint32_t textures[4][TEXTURE_HEIGHT][TEXTURE_WIDTH],
				t_map_data *data);
int			get_array_height(void **data);
void		calculate_rays(t_game *game);
void		ft_free_arr(void **data);
void		update_player_pos(t_player *player, int key, char **map);
void		rotate_player(t_player *player, double angle);
void		mouse_rotation(mlx_t *mlx, t_player *player);
bool		map_parsing(int ac, char *av[], t_game *game);
void		ft_fill_portail(t_map_data *data, char *file_data);

#endif