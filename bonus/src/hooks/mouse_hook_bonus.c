/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:16:20 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/12 16:10:25 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mouse_hook(int x, int y, t_data *data)
{
	t_player	*player;

	(void)y;
	player = &data->player;
	if (x > WINDOW_WIDTH / 2 + 2)
		player->mouse_direction = 0.06 * (x - WINDOW_WIDTH / 2);
	else if (x < WINDOW_WIDTH / 2 - 2)
		player->mouse_direction = -0.06 * (WINDOW_WIDTH / 2 - x);
	mlx_mouse_move(data->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	return (0);
}
