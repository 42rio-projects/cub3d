/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tile_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:49:41 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/11 17:50:53 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render_tile(t_image *image,
		uint32_t x_start, uint32_t y_start, uint32_t color)
{
	uint32_t	x_end;
	uint32_t	y_end;
	uint32_t	x;

	x_end = x_start + MINIMAP_SCALE;
	y_end = y_start + MINIMAP_SCALE;
	while (y_start < y_end)
	{
		x = x_start;
		while (x < x_end)
		{
			put_pixel(image, x, y_start, color);
			x++;
		}
		y_start++;
	}
}
