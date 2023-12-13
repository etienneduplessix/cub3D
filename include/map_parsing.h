

#ifndef MAP_PARSING_H
# define MAP_PARSING_H

# define ALLOWED_MAPCHARS "NSEW10 "
# include "cub.h" 
# include "../lib/libft/includes/libft.h"
# include "../lib/libft/includes/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct s_map_data
{
	char			*north_txt;
	char			*south_txt;
	char			*east_txt;
	char			*west_txt;
	unsigned char	floor_color[3];
	unsigned char	ceil_color[3];
	int				pos_player_x;
	int				pos_player_y;
	int				map_max_x;
	int				map_max_y;
	int				map_index;
	char			**map;
}	t_map_data;

typedef struct s_parse
{
	int	valid_north;
	int	valid_east;
	int	valid_south;
	int	valid_west;
	int	valid_floor;
	int	valid_ceil;
}	t_parse;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_mapInfo
{
	int			map_width;
	int			map_height;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	char		**texture_paths;
	char		**map;
}	t_mapInfo;



void		map_info_free(t_mapInfo *map_info);
bool		ft_error(t_mapInfo *map_info, char *error_msg);
t_mapInfo	*map_info_init(void);
bool			check_map_info(t_mapInfo *map_info);
uint32_t	rgb_to_hex(char **rgb_arr);
void	**ft_arrappend_void(void **arr, void *to_append);
char	**ft_arrappend(char **arr, char *to_append);
void	ft_arrfree(void **arr);
size_t	ft_arrlen(void **s);
bool			textureline_fill(t_mapInfo	*map_info, char **mapline_split);
bool			rgb_fill(t_mapInfo	*map_info, char **mapline_split);
bool			get_info(t_mapInfo	*map_info, char *map_line);
int		map_info_fill(t_mapInfo	*map_info, int map_fd);
t_mapInfo	*get_map(char *map_path); //THE ACTUAL MAIN FUNCTION

bool			is_map_line(char *map_line);
bool			process_map_arr(char *map_line, t_mapInfo *map_info, int map_fd);
#endif
