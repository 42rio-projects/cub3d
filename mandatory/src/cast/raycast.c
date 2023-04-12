/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:55:11 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/11 22:56:35 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_calc_variables(t_ray *ray, double pos_x, double pos_y)
{
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (pos_x - (int)pos_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((int)pos_x + 1.0 - pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (pos_y - (int)pos_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((int)pos_y + 1.0 - pos_y) * ray->delta_dist_y;
	}
}

static void	set_hit_variables(t_ray *ray, bool horizontal_hit)
{
	if (horizontal_hit == false)
	{
		ray->distance = (ray->side_dist_x - ray->delta_dist_x);
		if (ray->dir_x < 0)
			ray->hit_direction = 'W';
		else
			ray->hit_direction = 'E';
	}
	else
	{
		ray->distance = (ray->side_dist_y - ray->delta_dist_y);
		if (ray->dir_y < 0)
			ray->hit_direction = 'N';
		else
			ray->hit_direction = 'S';
	}
}

static void	closest_interception(t_player *player, t_scene *scene, t_ray *ray)
{
	int		map_x;
	int		map_y;
	bool	horizontal_hit;

	map_x = (int)player->pos_x;
	map_y = (int)player->pos_y;
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			map_x += ray->step_x;
			horizontal_hit = false;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			map_y += ray->step_y;
			horizontal_hit = true;
		}
		if (is_wall_at(scene, map_x, map_y))
			break ;
	}
	set_hit_variables(ray, horizontal_hit);
}

void	raycast(t_player *player, t_scene *scene, t_ray *ray)
{
	set_calc_variables(ray, player->pos_x, player->pos_y);
	closest_interception(player, scene, ray);
}
