
# include "../../include/cub.h"

static int		load_file(uint32_t pixl_arr[TEXTURE_HEIGHT][TEXTURE_WIDTH],
					char *txt_file);
static void		fill_array(uint32_t pixl_arr[TEXTURE_HEIGHT][TEXTURE_WIDTH],
					uint32_t *pixels_raw, uint32_t width, uint32_t height);
static uint32_t	switch_color_bytes(uint32_t bad);

int	load_textures(uint32_t textures[4][TEXTURE_HEIGHT][TEXTURE_WIDTH],
		t_map_data *data)
{
	if (load_file(textures[TXT_NORTH], data->north_txt))
	{
		free_map_data(data);
		exit(1);
	}
	if (load_file(textures[TXT_SOUTH], data->south_txt))
	{
		free_map_data(data);
		exit(1);
	}
	if (load_file(textures[TXT_EAST], data->east_txt))
	{
		free_map_data(data);
		exit(1);
	}
	if (load_file(textures[TXT_WEST], data->west_txt))
	{
		free_map_data(data);
		exit(1);
	}
	return (0);
}

static int	load_file(uint32_t pixl_arr[TEXTURE_HEIGHT][TEXTURE_WIDTH],
				char *txt_file)
{
	mlx_texture_t	*texture;

	if (!txt_file)
		return (1);
	texture = mlx_load_png(txt_file);
	if (!texture)
	{
		ft_dprintf(2, "%s: %s\n", txt_file, mlx_strerror(mlx_errno));
		return (1);
	}
	if (texture->height != TEXTURE_HEIGHT
		|| texture->width != TEXTURE_WIDTH)
	{
		ft_dprintf(2, "The `%s' dimensions do not match the ones set in the"
			" header file\n", txt_file);
		mlx_delete_texture(texture);
		return (1);
	}
	fill_array(pixl_arr, (uint32_t *)texture->pixels,
		texture->width, texture->height);
	mlx_delete_texture(texture);
	return (0);
}

static void	fill_array(uint32_t pixel_arr[TEXTURE_HEIGHT][TEXTURE_WIDTH],
						uint32_t *pixels_raw, uint32_t width, uint32_t height)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	color;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			color = switch_color_bytes(pixels_raw[i * width + j]);
			pixel_arr[i][j] = color;
			j++;
		}
		i++;
	}
}

static uint32_t	switch_color_bytes(uint32_t bad)
{
	uint32_t	good;

	good = ((bad & 0xff) << 24) | (((bad >> 8) & 0xff) << 16)
		| (((bad >> 16) & 0xff) << 8) | bad >> 24;
	return (good);
}

static t_txt_side	get_texture_side(t_vector_i *step, int *side);
static void			draw_texture(int x, t_raycast *raycast, t_game *game,
						int side);

void	draw_line(int x, t_raycast *raycast, t_game *game)
{
	int	y;
	int	txt_side;

	y = 0;
	if (raycast->draw_start >= SCREEN_HEIGHT || raycast->draw_end < 0)
		return ;
	txt_side = get_texture_side(&raycast->step, &raycast->side);
	while (y < raycast->draw_start)
	{
		mlx_put_pixel(game->img, x, y, game->bg_colors[CLR_TOP]);
		y++;
	}
	draw_texture(x, raycast, game, txt_side);
	y = raycast->draw_end;
	while ((uint32_t)y < SCREEN_HEIGHT)
	{
		mlx_put_pixel(game->img, x, y, game->bg_colors[CLR_BOT]);
		y++;
	}
}

static void	draw_texture(int x, t_raycast *rc, t_game *game, int side)
{
	t_texture_draw	txt_data;
	int				y;

	if (rc->side == 0)
		txt_data.wall_x = game->player.pos.y + rc->wall_dist * rc->ray_dir.y;
	else
		txt_data.wall_x = game->player.pos.x + rc->wall_dist * rc->ray_dir.x;
	txt_data.wall_x -= floor(txt_data.wall_x);
	txt_data.texture_coord.x = txt_data.wall_x * TEXTURE_WIDTH;
	if (rc->side == 0 && rc->ray_dir.x > 0)
		txt_data.texture_coord.x = TEXTURE_WIDTH - txt_data.texture_coord.x - 1;
	if (rc->side == 1 && rc->ray_dir.y < 0)
		txt_data.texture_coord.x = TEXTURE_WIDTH - txt_data.texture_coord.x - 1;
	txt_data.step = 1.0 * TEXTURE_HEIGHT / rc->line_height;
	txt_data.texture_pos = (rc->draw_start - game->img->height
			/ 2.0 + rc->line_height / 2.0) * txt_data.step;
	y = rc->draw_start;
	while (y < rc->draw_end)
	{
		txt_data.texture_coord.y = (int)txt_data.texture_pos
			& (TEXTURE_HEIGHT - 1);
		txt_data.texture_pos += txt_data.step;
		mlx_put_pixel(game->img, x, y++, game->textures_pxls[side]
		[txt_data.texture_coord.y][txt_data.texture_coord.x]);
	}
}

static t_txt_side	get_texture_side(t_vector_i *step, int *side)
{
	if (*side == 0 && step->x < 0)
		return (TXT_NORTH);
	if (*side == 0 && step->x > 0)
		return (TXT_SOUTH);
	if (*side == 1 && step->y < 0)
		return (TXT_EAST);
	if (*side == 1 && step->y > 0)
		return (TXT_WEST);
	return (0);
}
