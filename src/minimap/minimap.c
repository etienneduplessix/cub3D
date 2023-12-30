/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etienned <etienned@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:29:01 by etienned          #+#    #+#             */
/*   Updated: 2023/12/25 20:33:53 by etienned         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"cub.h"

void draw_square(t_data *data, t_square *square)
{
	int x = square->x;
	int y = square->y;
	int size = square->size;
	int color = 0xFF0000; // Red color for the square, you can change this

	while (y < square->y + size)
	{
		x = square->x;
		while (x < square->x + size)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, color);
			x++;
		}
		y++;
	}
}
void	draw_minimap(void)
{
	t_data data;
	t_square square = {100, 100, 50}; // Square position (x, y) and size
	draw_square(&data, &square);
}