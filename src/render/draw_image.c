/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:02:48 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/06 18:26:55 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void draw_minimap(t_data *data, t_player* player, t_scene* scene)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;
	t_image		*image;

	image = &data->image;
	y = 0;
	while (scene->map_grid[y])
	{
		x = 0;
		while (scene->map_grid[y][x])
		{
			if (scene->map_grid[y][x] == '1')
				color = MINIMAP_WALL_COLOR;
			else if (scene->map_grid[y][x] == ' ')
				color = MINIMAP_EMPTY_COLOR;
			else
				color = MINIMAP_FLOOR_COLOR;
			render_tile(image, x * MINIMAP_SCALE, y * MINIMAP_SCALE, color);
			x++;
		}
		y++;
	}
	render_tile(image, round(player->pos_x * MINIMAP_SCALE) - 2,
	round(player->pos_y * MINIMAP_SCALE) - 2, PLAYER_COLOR);
}

void draw_image(t_data* data)
{
  	raycast(data, &data->player, &data->scene);
	draw_minimap(data, &data->player, &data->scene);
}