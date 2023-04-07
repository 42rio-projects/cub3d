/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:18:16 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/07 01:34:09 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_texture(t_data *data, t_draw_info *info, int x)
{
	int			texture_y;
	uint32_t	y;
	uint32_t	color;
	t_texture	*texture;

	texture = info->texture;
	y = info->wall_start - 1;
	while (++y < info->wall_end)
	{
		texture_y = (int)info->texture_pos & (texture->height - 1);
		info->texture_pos += info->step;
		color = texture->addr[(texture->height * texture_y + info->texture_x)];
		put_pixel(&data->image, WINDOW_WIDTH - x, y, color);
	}
}
