/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:02:48 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/05 13:02:43 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void draw_minimap(t_data *data, t_player* player, t_scene* scene)
{
  t_image*  image;

  image = &data->main_image;
	// draw the grid
	uint32_t color;
	for (uint32_t pos_y = 0; scene->map_grid[pos_y]; pos_y++) {
		for (uint32_t pos_x = 0; scene->map_grid[pos_y][pos_x]; pos_x++) {
			if (scene->map_grid[pos_y][pos_x] == '1')
				color = MINIMAP_WALL_COLOR;
			else if (scene->map_grid[pos_y][pos_x] == ' ')
				color = MINIMAP_EMPTY_COLOR;
			else
				color = MINIMAP_FLOOR_COLOR;
			render_tile(image, pos_x * MINIMAP_SCALE, pos_y * MINIMAP_SCALE, color);
		}
	}

	// draw player
	render_tile(image, round(player->pos_x * MINIMAP_SCALE) - 2,
	round(player->pos_y * MINIMAP_SCALE) - 2, PLAYER_COLOR);

	// draw rays
	t_ray* rays = player->rays;
	for (uint32_t x = 0; x < NUM_RAYS; x++) {
		dda(data, round(player->pos_x * MINIMAP_SCALE),
		round(player->pos_y * MINIMAP_SCALE),
		round(rays[x].wall_hit_x * MINIMAP_SCALE),
		round(rays[x].wall_hit_y * MINIMAP_SCALE));
	}
}

static void draw_walls(t_image* image, t_data* data)
{
	t_player* player = &data->player;
	t_ray* rays = player->rays;
	t_texture* texture;

	for (uint32_t x = 0; x < WINDOW_WIDTH; x++) {
		int line_height = (int)(WINDOW_HEIGHT / rays[x].distance);
		int draw_start = (WINDOW_HEIGHT / 2) - (line_height / 2);
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = draw_start + line_height;
		if (draw_end >= WINDOW_HEIGHT)
			draw_end = WINDOW_HEIGHT;

		double wall_x;
		if (rays[x].wall_hit_horizontal)
			wall_x = player->pos_x + rays[x].distance * rays[x].dir_x;
		else
			wall_x = player->pos_y + rays[x].distance * rays[x].dir_y;
		wall_x -= (int)wall_x;

		if (rays[x].wall_hit_horizontal && rays[x].dir_y < 0)
      texture = &data->scene.no_texture;
		else if (!rays[x].wall_hit_horizontal && rays[x].dir_x > 0)
      texture = &data->scene.ea_texture;
		else if (!rays[x].wall_hit_horizontal && rays[x].dir_x < 0)
      texture = &data->scene.we_texture;
    else
      texture = &data->scene.so_texture;

		int texture_x = (int)(wall_x * (double)texture->width);
		if (!rays[x].wall_hit_horizontal && rays[x].dir_x > 0)
			texture_x = texture->width - texture_x - 1;
		if (rays[x].wall_hit_horizontal && rays[x].dir_y < 0)
			texture_x = texture->width - texture_x - 1;

		double step = 1.0 * texture->height / line_height;
		double texture_pos = (draw_start - WINDOW_HEIGHT / 2 + line_height / 2) * step;
		for (int y = draw_start; y < draw_end; y++) {
			int texture_y = (int)texture_pos & (texture->height - 1);
			texture_pos += step;
			uint32_t color = texture->addr[(texture->height * texture_y + texture_x)];
			put_pixel(image, WINDOW_WIDTH - x, y, color);
		}
	}
}

void draw_image(t_image* image, t_data* data) {
  	raycast(&data->player, &data->scene);
	draw_walls(image, data);
	draw_minimap(data, &data->player, &data->scene);
}