/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:56:30 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/05 13:02:09 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_background(t_image* image, uint32_t floor_color, uint32_t ceil_color)
{
	uint32_t ceil_end;
  uint32_t y;
  uint32_t x;

  ceil_end = WINDOW_HEIGHT / 2;
  y = -1;
  while(++y < ceil_end)
  {
    x = -1;
    while(++x < WINDOW_WIDTH)
    	put_pixel(image, x, y, ceil_color);
  }
  while(y < WINDOW_HEIGHT)
  {
    x = -1;
    while(++x < WINDOW_WIDTH)
    	put_pixel(image, x, y, floor_color);
    y++;
  }
}
