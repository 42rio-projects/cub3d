/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:56:07 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/11 22:43:57 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall_at(t_scene *scene, int x, int y)
{
	if (x < 0 || y < 0 || x >= (int)scene->map_width
		|| y >= (int)scene->map_height)
		return (true);
	if (scene->map_grid[y][x] == '1')
		return (true);
	return (false);
}
