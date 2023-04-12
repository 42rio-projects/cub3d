/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:40:48 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/11 17:50:06 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	set_player_position(char **map_grid, t_player *player)
{
	uint32_t	y;
	uint32_t	x;

	y = -1;
	while (map_grid[++y])
	{
		x = -1;
		while (map_grid[y][++x])
		{
			if (ft_strchr("NSWE", map_grid[y][x]))
			{
				if (player->pos_x != 0 || player->pos_y != 0)
					return (throw_error("The map must have only 1 player!\n"));
				player->pos_x = x + 0.5;
				player->pos_y = y + 0.5;
			}
		}
	}
	if (player->pos_x == 0 || player->pos_y == 0)
		return (throw_error("Player not found\n"));
	return (0);
}

static void	set_player_direction(char **map_grid, t_player *player)
{
	char	orientation;

	orientation = map_grid[(uint32_t)player->pos_y][(uint32_t)player->pos_x];
	if (orientation == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (orientation == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (orientation == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	else if (orientation == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
}

static void	set_player_plane(char **map_grid, t_player *player)
{
	char	orientation;

	orientation = map_grid[(uint32_t)player->pos_y][(uint32_t)player->pos_x];
	if (orientation == 'N')
	{
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (orientation == 'S')
	{
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (orientation == 'W')
	{
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (orientation == 'E')
	{
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

bool	player_init(t_player *player, t_scene *scene)
{
	ft_bzero(player, sizeof(t_player));
	if (set_player_position(scene->map_grid, player))
		return (1);
	set_player_direction(scene->map_grid, player);
	set_player_plane(scene->map_grid, player);
	return (0);
}
