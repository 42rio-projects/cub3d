/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:40:37 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/11 17:49:55 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	image_init(t_data *data)
{
	data->win = mlx_new_window(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	data->image.img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bpp, &data->image.size_len, &data->image.endian);
	draw_image(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->image.img, 0, 0);
}
