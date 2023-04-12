/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_released_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:17:38 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/12 16:04:59 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	key_released(int keycode, t_data *data)
{
	t_player	*player;

	player = &data->player;
	if (keycode == W)
		player->walk_direction--;
	else if (keycode == A)
		player->turn_direction++;
	else if (keycode == S)
		player->walk_direction++;
	else if (keycode == D)
		player->turn_direction--;
	return (0);
}
