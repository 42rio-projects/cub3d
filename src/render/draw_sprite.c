/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:12:09 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/10 15:52:22 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sort_sprites(t_sprite *sprites)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = -1;
	while (++i < NUM_SPRITES)
	{
		j = -1;
		while (++j < NUM_SPRITES - 1)
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

static void	set_orders_and_distances(t_sprite *sprites, t_player *player)
{
	int	i;

	i = -1;
	while (++i < NUM_SPRITES)
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
	set_orders_and_distances(sprites, &data->player);
	sort_sprites(sprites);
	draw_animation(data, sprites);
}
