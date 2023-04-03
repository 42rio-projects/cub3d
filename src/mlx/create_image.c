/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:41:06 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/03 13:12:03 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(t_data *info)
{
	int	x;
	int	y;

	x = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			my_mlx_pixel_put(info, y, x, 8421504);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win, info->img, 0, 0);
}
