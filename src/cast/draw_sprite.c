/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:12:09 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/09 02:27:34 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//sort sprites from furthest to the closest distance
static void	sort_order_and_distance(t_sprite *sprites)
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

void	draw_sprite(t_data *data, t_sprite *sprites)
{
	int			i;

	sprites_init(data);
	sort_order_and_distance(sprites);
	i = -1;
	while (++i < NUM_SPRITES)
		spritecast(&sprites[sprites[i].order], &data->player, data);
}
