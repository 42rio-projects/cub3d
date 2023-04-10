/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:12:27 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/10 15:27:53 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_textures(t_data *data, t_sprite *sprites)
{
	load_texture(data, &sprites[0].textures,
		"./textures/xpm/fire.xpm", "visao\n");
	load_texture(data, &sprites[1].textures,
		"./textures/xpm/fire.xpm", "visao\n");
	load_texture(data, &sprites[2].textures,
		"./textures/xpm/fire.xpm", "visao\n");
}

static void	set_coordinates(t_sprite *sprites)
{
	sprites[0].x = 14.5;
	sprites[0].y = 2.5;
	sprites[1].x = 15.5;
	sprites[1].y = 2.5;
	sprites[2].x = 16.5;
	sprites[2].y = 2.5;
}

void	sprites_init(t_data *data)
{
	t_sprite	*sprites;

	sprites = data->sprites;
	set_coordinates(sprites);
	set_textures(data, sprites);
}
