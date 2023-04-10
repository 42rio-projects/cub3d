/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:02:48 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/10 14:30:50 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_minimap(t_data *data, t_player *player, t_scene *scene)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;
	t_image		*image;

	image = &data->image;
	y = -1;
	while (scene->map_grid[++y])
	{
		x = -1;
		while (scene->map_grid[y][++x])
		{
			if (scene->map_grid[y][x] == '1' || scene->map_grid[y][x] == '2')
				color = MINIMAP_WALL_COLOR;
			else if (scene->map_grid[y][x] == ' ')
				continue ;
			else
				color = MINIMAP_FLOOR_COLOR;
			render_tile(image, x * MINIMAP_SCALE, y * MINIMAP_SCALE, color);
		}
	}
	render_tile(image, round(player->pos_x * MINIMAP_SCALE - MINIMAP_SCALE / 2),
		round(player->pos_y * MINIMAP_SCALE - MINIMAP_SCALE / 2), PLAYER_COLOR);
}

void	draw_image(t_data *data)
{
	draw_ceil_wall_floor(data, &data->player, &data->scene);
	draw_sprite(data, data->sprites);
	draw_minimap(data, &data->player, &data->scene);
}
