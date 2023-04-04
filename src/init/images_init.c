/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:40:37 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/04 17:44:08 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	images_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	data->background_image.img = mlx_new_image(data->mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->background_image.addr = mlx_get_data_addr(data->background_image.img, &data->background_image.bpp, &data->background_image.size_len, &data->background_image.endian);
	draw_background(&data->background_image, data->floor_color, data->ceil_color);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->background_image.img, 0, 0);
	data->image.img = mlx_new_image(data->mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bpp, &data->image.size_len, &data->image.endian);
	draw_image(&data->image, data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->image.img, 0, 0);
}
