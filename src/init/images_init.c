/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:40:37 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/04 17:56:08 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	images_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	data->background_image.img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->background_image.addr = mlx_get_data_addr(data->background_image.img, &data->background_image.bpp, &data->background_image.size_len, &data->background_image.endian);
	draw_background(&data->background_image, data->scene.floor_color, data->scene.ceil_color);
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->background_image.img, 0, 0);
	data->main_image.img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->main_image.addr = mlx_get_data_addr(data->main_image.img, &data->main_image.bpp, &data->main_image.size_len, &data->main_image.endian);
	draw_image(&data->main_image, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->main_image.img, 0, 0);
}
