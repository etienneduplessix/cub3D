/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etienneduplessix <etienneduplessix@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:30 by achretie          #+#    #+#             */
/*   Updated: 2023/12/20 10:54:27 by etiennedupl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "constants.h"
# include "game_struct.h"
# include "parsing.h"
# include "minimap.h"
# include "matrix.h"
# include "vector.h"
# include <stdlib.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include <memory.h>
# include "../lib/libft/includes/libft.h"
# include "../lib/libft/includes/get_next_line.h"
# include "../lib/libft/includes/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

int		load_textures(uint32_t textures[4][TEXTURE_HEIGHT][TEXTURE_WIDTH],
			t_map_data *data);
void	draw_minimap(t_game *game);
void	calculate_rays(t_game *game);
void ft_free_arr(void **data) ;
void	update_player_pos(t_player *player, int key);
void	rotate_player(t_player *player, double angle);
void	map_parsing(int ac, char *av[], t_game *game);

#endif
