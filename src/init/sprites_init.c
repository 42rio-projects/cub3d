/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:12:27 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/09 21:45:30 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprites_init(t_data *data)
{
	t_sprite	*sprites;
	t_player	*player;
	int			i;

	sprites = data->sprites;
	player = &data->player;
	sprites[0].x = 3.5;
	sprites[0].y = 3.5;
	load_texture(data, &sprites[0].texture[0], "./textures/xpm/fire1.xpm", "visao\n");
	load_texture(data, &sprites[0].texture[1], "./textures/xpm/fire2.xpm", "visao\n");
	load_texture(data, &sprites[0].texture[2], "./textures/xpm/fire3.xpm", "visao\n");

	sprites[1].x = 4.5;
	sprites[1].y = 4.5;
	load_texture(data, &sprites[1].texture[0], "./textures/xpm/barrel.xpm", "visao\n");
	load_texture(data, &sprites[1].texture[1], "./textures/xpm/wood.xpm", "visao\n");
	load_texture(data, &sprites[1].texture[2], "./textures/xpm/brick.xpm", "visao\n");
	sprites[2].x = 2.5;
	sprites[2].y = 2.5;
	load_texture(data, &sprites[2].texture[0], "./textures/xpm/blue.xpm", "visao\n");
	load_texture(data, &sprites[2].texture[1], "./textures/xpm/brick.xpm", "visao\n");
	load_texture(data, &sprites[2].texture[2], "./textures/xpm/wood.xpm", "visao\n");
	i = -1;
	while (++i < NUM_SPRITES)
	{
		sprites[i].order = i;
		sprites[i].distance = ((player->pos_x - sprites[i].x) * (player->pos_x - sprites[i].x) + (player->pos_y - sprites[i].y) * (player->pos_y - sprites[i].y)); //sqrt not taken, unneeded
	}
}
