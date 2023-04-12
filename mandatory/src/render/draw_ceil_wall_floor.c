/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_wall_floor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:50:25 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/11 23:21:57 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_wall_texture(t_data *data, t_draw_info *info, int x)
{
	int			texture_y;
	uint32_t	y;
	uint32_t	color;
	t_texture	*texture;

	texture = info->texture;
	y = info->wall_start - 1;
	while (++y < info->wall_end)
	{
		texture_y = (int)info->texture_pos & (texture->height - 1);
		info->texture_pos += info->step;
		color = texture->addr[(texture->height * texture_y + info->texture_x)];
		put_pixel(&data->image, WINDOW_WIDTH - x, y, color);
	}
}

static void	draw_ceil_and_floor(t_data *data, t_draw_info *info, int x)
{
	uint32_t	y;

	y = -1;
	while (++y < info->wall_start)
		put_pixel(&data->image, WINDOW_WIDTH - x, y, data->scene.ceil_color);
	y = info->wall_end - 1;
	while (++y < WINDOW_HEIGHT)
		put_pixel(&data->image, WINDOW_WIDTH - x, y, data->scene.floor_color);
}

void	draw_ceil_wall_floor(t_data *data, t_player *player, t_scene *scene)
{
	t_draw_info	info;
	t_ray		ray;
	double		camera_x;
	uint32_t	x;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
		ray.dir_x = player->dir_x + player->plane_x * camera_x;
		ray.dir_y = player->dir_y + player->plane_y * camera_x;
		raycast(player, scene, &ray);
		set_draw_info(data, player, &ray, &info);
		draw_ceil_and_floor(data, &info, x);
		draw_wall_texture(data, &info, x);
	}
}
