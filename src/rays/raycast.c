/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:50:25 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/04 18:14:40 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void raycast(t_player *player, t_scene *scene)
{
  uint32_t i;
  i = -1;
  while(++i < NUM_RAYS)
  {
		rays_init(player, player->rays + i, 2 * i / (double)NUM_RAYS - 1);
		cast(player, scene, player->rays + i);
  }
}