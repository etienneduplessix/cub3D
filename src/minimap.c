

# include "../include/cub.h"

void	draw_square(t_game *game, int x, int y, int color)
{
	int	x_max;
	int	y_max;

	x_max = x + 5;
	y_max = y + 5;
	while (y < y_max && (uint32_t)y < game->img->height)
	{
		while (x < x_max && (uint32_t)x < game->img->width)
		{
			mlx_put_pixel(game->img, x, y, color);
			x++;
		}
		x -= 5;
		y++;
	}
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (game->data.map[y])
	{
		x = 0;
		while (game->data.map[y][x])
		{
			if (game->data.map[y][x] == '1')
				color = 0x3DB3324C;
			else
				color = 0xFFFFFFFF;
			draw_square(game, x * 5, y * 5, color);
			x++;
		}
		y++;
	}
}
