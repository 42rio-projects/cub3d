/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:17:03 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/07 16:21:26 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed(int keycode, t_data *data)
{
	t_player	*player;

	player = &data->player;
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win);
		free_scene(&data->scene);
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
	return (0);
}
