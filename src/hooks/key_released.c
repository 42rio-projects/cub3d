/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_released.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:17:38 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/05 21:27:06 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_released(int keycode, t_data *data)
{
	t_player	*player;

	player = &data->player;
	if (keycode == W)
		player->walkDirection--;
	else if (keycode == A)
		player->turnDirection++;
	else if (keycode == S)
		player->walkDirection++;
	else if (keycode == D)
		player->turnDirection--;
	return (0);
}
