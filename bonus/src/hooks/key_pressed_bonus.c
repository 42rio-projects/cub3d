/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:17:03 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/11 17:49:23 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	open_door(t_scene *scene, t_player *player)
{
	int	pos_y;
	int	pos_x;

	pos_y = player->pos_y + player->dir_y * 1;
	pos_x = player->pos_x + player->dir_x * 1;
	if (scene->map_grid[pos_y][pos_x] == '2')
		scene->map_grid[pos_y][pos_x] = '0';
}

int	key_pressed(int keycode, t_data *data)
{
	t_player	*player;

	player = &data->player;
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win);
		free(data->image.img);
		free(data->image.addr);
		free_scene(&data->scene);
		free(data->sprites);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == W)
		player->walk_direction++;
	else if (keycode == A)
		player->turn_direction--;
	else if (keycode == S)
		player->walk_direction--;
	else if (keycode == D)
		player->turn_direction++;
	else if (keycode == E)
		open_door(&data->scene, &data->player);
	return (0);
}
