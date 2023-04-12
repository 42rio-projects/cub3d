/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:23:17 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/11 23:35:13 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_player(t_player *player)
{
	double	rotation;
	double	old_dir_x;
	double	old_plane_x;

	rotation = player->turn_direction * ROTATION_SPEED;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x
		* cos(rotation) - player->dir_y * sin(rotation);
	player->dir_y = old_dir_x * sin(rotation) + player->dir_y * cos(rotation);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x
		* cos(rotation) - player->plane_y * sin(rotation);
	player->plane_y = old_plane_x
		* sin(rotation) + player->plane_y * cos(rotation);
	player->pos_x = player->pos_x
		+ player->walk_direction * (player->dir_x * MOVE_SPEED);
	player->pos_y = player->pos_y
		+ player->walk_direction * (player->dir_y * MOVE_SPEED);
}

int	hook(t_data *data)
{
	update_player(&data->player);
	mlx_clear_window(data->mlx_ptr, data->win);
	draw_ceil_wall_floor(data, &data->player, &data->scene);
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->image.img, 0, 0);
	return (0);
}
