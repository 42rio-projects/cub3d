/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:13:25 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/10 01:06:26 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	spritecast(t_sprite *sprite, t_player *player)
{
	//translate sprite position to relative to camera
	sprite->camera_x = sprite->x - player->pos_x;
	sprite->camera_y = sprite->y - player->pos_y;
	//transform sprite with the inverse camera matrix
	sprite->inv_det = 1.0 / (player->plane_x * player->dir_y - player->dir_x * player->plane_y); //required for correct matrix multiplication
	sprite->transform_x = sprite->inv_det * (player->dir_y * sprite->camera_x - player->dir_x * sprite->camera_y);
	sprite->transform_y = sprite->inv_det * (-player->plane_y * sprite->camera_x + player->plane_x * sprite->camera_y); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])
	sprite->screen_x = (int)((WINDOW_WIDTH / 2) * (1 + sprite->transform_x / sprite->transform_y));
	//calculate height of the sprite on screen
	sprite->height = (int)fabs((WINDOW_HEIGHT / sprite->transform_y)); //using "sprite->transform_y" instead of the real distance prevents fisheye
	//calculate lowest and highest pixel to fill in current stripe
	sprite->draw_start_y = -sprite->height / 2 + WINDOW_HEIGHT / 2;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->height / 2 + WINDOW_HEIGHT / 2;
	if (sprite->draw_end_y >= WINDOW_HEIGHT)
		sprite->draw_end_y = WINDOW_HEIGHT - 1;
	//calculate width of the sprite
	sprite->width = (int)fabs((WINDOW_HEIGHT / sprite->transform_y));
	sprite->draw_start_x = -sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_end_x >= WINDOW_WIDTH)
		sprite->draw_end_x = WINDOW_WIDTH - 1;
}
