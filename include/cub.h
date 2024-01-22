
#ifndef  CUB_H
# define CUB_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "game_struct.h"
# include "constants.h"
# include "parsing.h"
# include "minimap.h"
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


int		load_textures(uint32_t textures[4][TEXTURE_HEIGHT][TEXTURE_WIDTH],
			t_map_data *data);
int get_array_height(void **data);
void	calculate_rays(t_game *game);
void ft_free_arr(void **data) ;
void	update_player_pos(t_player *player, int key, char **map);
void	rotate_player(t_player *player, double angle);
void	mouse_rotation(mlx_t *mlx, t_player *player);
void	map_parsing(int ac, char *av[], t_game *game);
static t_txt_side	get_texture_side(t_vector_i *step, int *side);
static void			draw_texture(int x, t_raycast *raycast, t_game *game,
						int side);
void	ft_fill_portail(t_map_data *data, char *file_data);


#endif
