/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:50:25 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/06 00:35:02 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void raycast(t_player *player, t_scene *scene, t_ray *rays)
{
  uint32_t i;

  i = -1;
  while(++i < WINDOW_WIDTH)
  {
		rays_init(player, rays + i, 2 * i / (double)WINDOW_WIDTH - 1);
		cast(player, scene, rays + i);
  }
}