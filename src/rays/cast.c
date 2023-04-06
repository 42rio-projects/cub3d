/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:55:11 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/04 17:08:39 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
	
void cast(t_player* player, t_scene *scene, t_ray* ray)
{
	// [map] position on the map
	int map_x;
  int map_y;
	// [delta] length of the ray from one x_side or y_side to next x_side or y_side
  double delta_dist_x;
	double delta_dist_y;
	// [side] length of ray from player position to next x_side and y_side
	double side_dist_x;
  double side_dist_y;
	// [step] what direction to step in
	int step_x;
  int step_y;
	// [hit] dda algorithm
	bool hit;

  map_x = (int)player->pos_x;
  map_y = (int)player->pos_y;

  delta_dist_x = (ray->dir_x == 0) ? 2147483647 : fabs(1 / ray->dir_x);
  delta_dist_y = (ray->dir_y == 0) ? 2147483647 : fabs(1 / ray->dir_y);

	// set varibles based on ray direction
	if (ray->dir_x < 0) {
		step_x = -1;
		side_dist_x = (player->pos_x - map_x) * delta_dist_x;
	}
	else {
		step_x = 1;
		side_dist_x = (map_x + 1.0 - player->pos_x) * delta_dist_x;
	}

	if (ray->dir_y < 0) {
		step_y = -1;
		side_dist_y = (player->pos_y - map_y) * delta_dist_y;
	}
	else {
		step_y = 1;
		side_dist_y = (map_y + 1.0 - player->pos_y) * delta_dist_y;
	}

  hit = false;
	while (hit == false) 
  {
		if (side_dist_x < side_dist_y) 
    {
			side_dist_x += delta_dist_x;
			map_x += step_x;
			ray->wall_hit_horizontal = false;
		}
		else 
    {
			side_dist_y += delta_dist_y;
			map_y += step_y;
			ray->wall_hit_horizontal = true;
		}
		if (is_wall_at(scene, map_x, map_y))
			hit = true;
	}

	// set the distance and the x/y where the wall was hit
	if(ray->wall_hit_horizontal == false)
		ray->distance = (side_dist_x - delta_dist_x);
	else
		ray->distance = (side_dist_y - delta_dist_y);
	ray->wall_hit_x = player->pos_x + (ray->distance * ray->dir_x);
	ray->wall_hit_y = player->pos_y + (ray->distance * ray->dir_y);
}