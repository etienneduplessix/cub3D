
#ifndef CUB_H
# define CUB_H


# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define PLAYER_SPEED 0.07
# define ROTATION_SPEED 0.23

# define TEXTURE_WIDTH 256
# define TEXTURE_HEIGHT 256
# define WIDTH		1350
# define HEIGHT		720
# define MINIMAP_WIDTH_FACTOR .2		// multiplied by gi->screen_w
# define BCKG_COLOR 0xFF			// black
# define WALL_COLOR 0xFFFFFFFF	// white
# define PLAYER_COLOR 0xFF0FF0FF

# include <stdlib.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include <memory.h>
# include "map_parsing.h"
# include "../lib/libft/includes/libft.h"
# include "../lib/libft/includes/get_next_line.h"
# include "../lib/libft/includes/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"


typedef struct s_vector_d
{
	double	x;
	double	y;
}	t_vector_d;

typedef struct s_vector_i
{
	int	x;
	int	y;
}	t_vector_i;

typedef enum e_bg_color{
	CLR_TOP,
	CLR_BOT,
}	t_bg_color;

typedef enum e_txt_side{
	TXT_NORTH,
	TXT_SOUTH,
	TXT_WEST,
	TXT_EAST
}	t_txt_side;

typedef struct s_player
{
	t_vector_d	pos;
	t_vector_d	dir;
	t_vector_d	plane;
}	t_player;

typedef struct s_game
{
	t_player	player;
	t_map_data	data;
	mlx_t		*mlx;
	mlx_image_t	*img;
	uint32_t	textures_pxls[4][TEXTURE_HEIGHT][TEXTURE_WIDTH];
	uint32_t	bg_colors[2];
}	t_game;

typedef struct s_texture_draw
{
	double		wall_x;
	double		step;
	t_vector_i	texture_coord;
	double		texture_pos;
}	t_texture_draw;


typedef struct s_raycast
{
	t_vector_d	ray_dir;
	t_vector_d	delta_dist;
	t_vector_d	side_dist;
	t_vector_i	map_pos;
	t_vector_i	step;
	double		wall_dist;
	bool		wall_hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_raycast;


typedef struct s_matrix
{
	double	a;
	double	b;
	double	c;
	double	d;
}	t_matrix;


int		load_textures(uint32_t textures[4][TEXTURE_HEIGHT][TEXTURE_WIDTH],t_map_data *data);

void	calculate_rays(t_game *game);

void	update_player_pos(t_player *player, int key);
void	rotate_player(t_player *player, double angle);
void	map_parsing(int ac, char *av[], t_game *game);

#endif 