/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:16:20 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/08 22:21:09 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_hook(int x, int y, t_data *data)
{
	t_player	*player;

	(void)y;
	player = &data->player;
	mlx_mouse_move(data->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	// mlx_mouse_move(data->mlx_ptr, data->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	if (x > WINDOW_WIDTH / 2 + 2)
		player->turn_direction = 1;
	else if (x < WINDOW_WIDTH / 2 - 2)
		player->turn_direction = -1;
	else
		player->turn_direction = 0;
	return (0);
}
