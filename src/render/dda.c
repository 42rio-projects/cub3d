/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:20:31 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/04 18:30:58 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void dda(t_data *data, int x0, int y0, int x1, int y1)
{
    int   dx;
    int   dy;
    int   steps;
    float x_inc;
    float y_inc;
    float x;
    float y;
    int   i;

    dx = x1 - x0;
    dy = y1 - y0;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    x_inc = dx / (float)steps;
    y_inc = dy / (float)steps;
    x = data->player.pos_x;
    y = data->player.pos_y;
    i = -1;
    while(++i <= steps)
    {
		    put_pixel(&data->main_image, x, y, RAY_COLOR);
        x += x_inc;
        y += y_inc;
    }
}