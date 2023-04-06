/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:20:31 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/06 14:30:59 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void plot_pixel(t_image* image, int x_start, int y_start, int x_end, int y_end,
						uint32_t x_distance, uint32_t y_distance, bool decide, uint32_t color)
{
	int pk = 2 * y_distance - x_distance;
	for (uint32_t i = 0; i <= x_distance; i++) {
		if (x_start < x_end)
			x_start++;
		else
			x_start--;
		if (pk < 0) {
			if (decide == false)
				put_pixel(image, x_start, y_start, color);
			else
				put_pixel(image, y_start, x_start, color);
			pk = pk + 2 * y_distance;
		}
		else {
			if (y_start < y_end)
				y_start++;
			else
				y_start--;
			if (decide == false)
				put_pixel(image, x_start, y_start, color);
			else
				put_pixel(image, y_start, x_start, color);
			pk = pk + 2 * y_distance - 2 * x_distance;
		}
	}
}

void render_line(t_image* image, int x_start, int y_start, int x_end, int y_end, uint32_t color)
{
	uint32_t x_distance = abs(x_end - x_start);
	uint32_t y_distance = abs(y_end - y_start);

	if (x_distance > y_distance)
		plot_pixel(image, x_start, y_start, x_end, y_end, x_distance, y_distance, 0, color);
	else
		plot_pixel(image, y_start, x_start, y_end, x_end, y_distance, x_distance, 1, color);
}