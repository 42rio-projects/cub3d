/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:12:27 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/12 00:39:40 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	set_coordinates(t_sprite *sprites, char **map_grid)
{
	int	y;
	int	x;

	y = -1;
	while (map_grid[++y])
	{
		x = -1;
		while (map_grid[y][++x])
		{
			if (map_grid[y][x] == 'F')
			{
				(*sprites).y = y + 0.5;
				(*sprites++).x = x + 0.5;
			}
		}
	}
}

static void	set_sprites_len(uint32_t *sprites_len, char **map_grid)
{
	int	y;
	int	x;

	*sprites_len = 0;
	y = -1;
	while (map_grid[++y])
	{
		x = -1;
		while (map_grid[y][++x])
		{
			if (map_grid[y][x] == 'F')
				(*sprites_len)++;
		}
	}
}

bool	sprites_init(t_data *data)
{
	t_scene	*scene;

	scene = &data->scene;
	set_sprites_len(&data->sprites_len, scene->map_grid);
	if (data->sprites_len > 0)
	{
		data->sprites = malloc(sizeof(t_sprite) * data->sprites_len);
		set_coordinates(data->sprites, scene->map_grid);
	}
	return (0);
}
