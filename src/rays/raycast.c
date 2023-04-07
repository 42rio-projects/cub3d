/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:50:25 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/06 17:31:01 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_player *player, t_scene *scene, t_ray *rays)
{
	uint32_t	i;

	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		rays[i].camera_x = 2 * i / (double)WINDOW_WIDTH - 1;
		rays[i].dir_x = player->dir_x + player->plane_x * rays[i].camera_x;
		rays[i].dir_y = player->dir_y + player->plane_y * rays[i].camera_x;
		cast(player, scene, rays + i);
	}
}
