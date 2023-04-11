/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:13:25 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/11 17:49:09 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	calc_draw_size(t_sprite *sprite)
{
	sprite->height = (int)fabs((WINDOW_HEIGHT / sprite->transform_y));
	sprite->width = (int)fabs((WINDOW_HEIGHT / sprite->transform_y));
	sprite->draw_start_y = -sprite->height / 2 + WINDOW_HEIGHT / 2;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->height / 2 + WINDOW_HEIGHT / 2;
	if (sprite->draw_end_y >= WINDOW_HEIGHT)
		sprite->draw_end_y = WINDOW_HEIGHT - 1;
	sprite->draw_start_x = -sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_end_x >= WINDOW_WIDTH)
		sprite->draw_end_x = WINDOW_WIDTH - 1;
}

static void	transform_sprite_coordinates(t_sprite *sprite, t_player *player)
{
	sprite->inv_det = 1.0 / (player->plane_x * player->dir_y
			- player->dir_x * player->plane_y);
	sprite->transform_x = sprite->inv_det * (player->dir_y * sprite->camera_x
			- player->dir_x * sprite->camera_y);
	sprite->transform_y = sprite->inv_det * (-player->plane_y * sprite->camera_x
			+ player->plane_x * sprite->camera_y);
	sprite->screen_x = (int)((WINDOW_WIDTH / 2)
			* (1 + sprite->transform_x / sprite->transform_y));
}

static void	set_sprite_camera(t_sprite *sprite, t_player *player)
{
	sprite->camera_x = sprite->x - player->pos_x;
	sprite->camera_y = sprite->y - player->pos_y;
}

void	spritecast(t_sprite *sprite, t_player *player)
{
	set_sprite_camera(sprite, player);
	transform_sprite_coordinates(sprite, player);
	calc_draw_size(sprite);
}
