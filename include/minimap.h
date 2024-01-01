
#ifndef MINIMAP_H  // Header guard to prevent multiple inclusion
# define MINIMAP_H

# include <cub.h>

void			draw_minimap(t_game *game);
void			draw_square(t_game *game, int x, int y, int color);

#endif