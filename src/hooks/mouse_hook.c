/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:16:20 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/08 20:24:19 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_hook(void *param)
{
	int		x;
	int		y;
	t_data	*data;

	data = param;
	mlx_mouse_move(data->mlx_ptr, data->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	mlx_mouse_get_pos(data->mlx_ptr, data->win, &x, &y);
	printf("x: %d | y: %d\n", x, y);
	return (0);
}
