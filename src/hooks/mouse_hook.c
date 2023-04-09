/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:16:20 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/08 21:27:06 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_hook(t_data *data)
{
	int			x;
	int			y;
	t_player	*player;

	(void)y;
	player = &data->player;
	mlx_mouse_get_pos(data->mlx_ptr, data->win, &x, &y);
	mlx_mouse_move(data->mlx_ptr, data->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	if (x > WINDOW_WIDTH / 2)
		player->turn_direction++;
	else if (x < WINDOW_WIDTH / 2)
		player->turn_direction--;
	return (0);
}
