/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_strip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:43:25 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/06 18:20:17 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_draw_info(t_ray *ray, int *line_height, int *draw_start, int *draw_end)
{
	*line_height = (int)(WINDOW_HEIGHT / ray->distance);
	*draw_start = (WINDOW_HEIGHT / 2) - (*line_height / 2);
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = *draw_start + *line_height;
	if (*draw_end > WINDOW_HEIGHT)
		*draw_end = WINDOW_HEIGHT;
}

static void	draw_ceil_and_floor(t_data *data, int draw_start, int draw_end, int x)
{
	uint32_t	y;

	y = -1;
	while (++y < draw_start)
		put_pixel(&data->image, WINDOW_WIDTH - x, y, data->scene.ceil_color);
	y = draw_end - 1;
	while (++y < WINDOW_HEIGHT)
		put_pixel(&data->image, WINDOW_WIDTH - x, y, data->scene.floor_color);
}

static void	draw_texture(t_data *data, int draw_start, int draw_end, int x)
{
	uint32_t	color;
	int			texture_y;
	uint32_t	y;

	y = draw_start - 1;
	while (++y < draw_end)
	{
		texture_y = (int)texture_pos & (texture->height - 1);
		texture_pos += step;
		color = texture->addr[(texture->height * texture_y + texture_x)];
		put_pixel(&data->image, WINDOW_WIDTH - x, y, color);
	}
}

void	draw_wall_strip(t_data *data, t_player *player, t_ray *ray, uint32_t x)
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	t_texture	*texture;

	set_draw_info(ray, &line_height, &draw_start, &draw_end);

	double wall_x;
	if (ray->hit_direction == 'N' || ray->hit_direction == 'S')
		wall_x = player->pos_x + ray->distance * ray->dir_x;
	else
		wall_x = player->pos_y + ray->distance * ray->dir_y;
	wall_x -= (int)wall_x;

	if (ray->hit_direction == 'N')
		texture = &data->scene.no_texture;
	else if (ray->hit_direction == 'E')
		texture = &data->scene.ea_texture;
	else if (ray->hit_direction == 'W')
		texture = &data->scene.we_texture;
	else
		texture = &data->scene.so_texture;

	int texture_x = (int)(wall_x * (double)texture->width);
	if (ray->hit_direction == 'N')
		texture_x = texture->width - texture_x - 1;
	if (ray->hit_direction == 'W')
		texture_x = texture->width - texture_x - 1;

	double step = 1.0 * texture->height / line_height;
	double texture_pos = (draw_start - WINDOW_HEIGHT / 2 + line_height / 2) * step;
	draw_ceil_and_floor(data, draw_start, draw_end, x);
	draw_texture();
}
