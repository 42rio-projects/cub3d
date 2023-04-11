/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:12:09 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/11 17:50:43 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	sort_sprites(t_sprite *sprites, uint32_t sprites_len)
{
	t_sprite	tmp;
	uint32_t	i;
	uint32_t	j;

	i = -1;
	while (++i < sprites_len)
	{
		j = -1;
		while (++j < sprites_len - 1)
		{
			if (sprites[j].distance < sprites[j + 1].distance)
			{
				tmp.distance = sprites[j].distance;
				tmp.order = sprites[j].order;
				sprites[j].distance = sprites[j + 1].distance;
				sprites[j].order = sprites[j + 1].order;
				sprites[j + 1].distance = tmp.distance;
				sprites[j + 1].order = tmp.order;
			}
		}
	}
}

static void	set_orders_and_distances(t_sprite *sprites, t_data *data)
{
	t_player	*player;
	uint32_t	i;

	player = &data->player;
	i = -1;
	while (++i < data->sprites_len)
	{
		sprites[i].order = i;
		sprites[i].distance = ((player->pos_x - sprites[i].x)
				* (player->pos_x - sprites[i].x)
				+ (player->pos_y - sprites[i].y)
				* (player->pos_y - sprites[i].y));
	}
}

void	draw_sprite(t_data *data, t_sprite *sprites)
{
	set_orders_and_distances(sprites, data);
	sort_sprites(sprites, data->sprites_len);
	draw_animation(data, sprites);
}
