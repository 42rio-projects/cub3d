/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_and_floor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:18:37 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/07 01:19:46 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceil_and_floor(t_data *data, t_draw_info *info, int x)
{
	uint32_t	y;

	y = -1;
	while (++y < info->wall_start)
		put_pixel(&data->image, WINDOW_WIDTH - x, y, data->scene.ceil_color);
	y = info->wall_end - 1;
	while (++y < WINDOW_HEIGHT)
		put_pixel(&data->image, WINDOW_WIDTH - x, y, data->scene.floor_color);
}
