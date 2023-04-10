/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:12:27 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/10 01:25:38 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//sort sprites from furthest to the closest distance
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

void	sprites_init(t_data *data)
{
	t_sprite	*sprites;
	t_player	*player;
	int			i;

	sprites = data->sprites;
	player = &data->player;
	sprites[0].x = 3.5;
	sprites[0].y = 3.5;
	load_texture(data, &sprites[0].textures, "./textures/xpm/fire.xpm", "visao\n");
	sprites[1].x = 4.5;
	sprites[1].y = 4.5;
	load_texture(data, &sprites[1].textures, "./textures/xpm/fire.xpm", "visao\n");
	sprites[2].x = 2.5;
	sprites[2].y = 2.5;
	load_texture(data, &sprites[2].textures, "./textures/xpm/fire.xpm", "visao\n");
	i = -1;
	while (++i < NUM_SPRITES)
	{
		sprites[i].order = i;
		sprites[i].distance = ((player->pos_x - sprites[i].x) * (player->pos_x - sprites[i].x) + (player->pos_y - sprites[i].y) * (player->pos_y - sprites[i].y)); //sqrt not taken, unneeded
	}
	sort_sprites(sprites);
}
