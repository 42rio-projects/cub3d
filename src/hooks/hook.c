/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:23:17 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/06 12:57:54 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_player(t_player *player, t_scene *scene)
{
	double	rotation;
	double	old_dir_x;
	double	old_plane_x;
	double	new_x;
	double	new_y;

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
	new_x = player->pos_x
		+ player->walk_direction * (player->dir_x * MOVE_SPEED);
	new_y = player->pos_y
		+ player->walk_direction * (player->dir_y * MOVE_SPEED);
	if (is_wall_at(scene, new_x, player->pos_y) == false)
		player->pos_x = new_x;
	if (is_wall_at(scene, player->pos_x, new_y) == false)
		player->pos_y = new_y;
}

int	hook(void *param)
{
	t_data	*data;

	data = param;
	if (data->close_game)
	{
		mlx_destroy_window(data->mlx_ptr, data->win);
		return (1);
	}
	update_player(&data->player, &data->scene);
	mlx_clear_window(data->mlx_ptr, data->win);
	draw_image(&data->image, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->image.img, 0, 0);
	return (0);
}
