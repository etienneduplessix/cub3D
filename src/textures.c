/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:06:06 by zabdulza          #+#    #+#             */
/*   Updated: 2024/02/07 15:40:54 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

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
