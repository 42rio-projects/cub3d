/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:50:25 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/07 01:11:16 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_data *data, t_player *player, t_scene *scene)
{
	t_ray		ray;
	double		camera_x;
	uint32_t	i;

	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		camera_x = 2 * i / (double)WINDOW_WIDTH - 1;
		ray.dir_x = player->dir_x + player->plane_x * camera_x;
		ray.dir_y = player->dir_y + player->plane_y * camera_x;
		cast(player, scene, &ray);
		draw_wall_strip(data, player, &ray, i);
	}
}
