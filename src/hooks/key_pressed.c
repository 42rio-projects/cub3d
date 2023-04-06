/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:17:03 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/06 12:50:10 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed(int keycode, t_data *data)
{
	t_player	*player;

	player = &data->player;
	if (keycode == ESC)
		data->close_game = 1;
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
