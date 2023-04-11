/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:12:27 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/11 17:50:12 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	set_textures(t_data *data, t_texture *texture)
{
	t_sprite	*sprites;
	uint32_t	i;

	sprites = data->sprites;
	i = -1;
	while (++i < data->sprites_len)
		sprites[i].texture = texture;
}

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

static int	set_sprites_len(uint32_t *sprites_len, char **map_grid)
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
	if (*sprites_len == 0)
		return (1);
	return (0);
}

bool	sprites_init(t_data *data)
{
	if (set_sprites_len(&data->sprites_len, data->scene.map_grid))
		return (throw_error("Map must have at least 1 sprite!\n"));
	data->sprites = malloc(sizeof(t_sprite) * data->sprites_len);
	set_coordinates(data->sprites, data->scene.map_grid);
	set_textures(data, &data->scene.s1_texture);
	return (0);
}
