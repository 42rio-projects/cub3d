/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:50:25 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/09 02:19:52 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceil_wall_floor(t_data *data, t_player *player, t_scene *scene)
{
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
		data->z_buffer[x] = ray.distance;
		draw_vertical_line(data, player, &ray, x);
	}
}
