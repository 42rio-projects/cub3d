/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:13:25 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/09 02:29:29 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	spritecast(t_sprite *sprite, t_player *player, t_data *data)
{
	int			texture_y;
	int			texture_x;
	int			y;
	int			d;
	int			color;
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
	//loop through every vertical stripe of the sprite on screen
	while (sprite->draw_start_x < sprite->draw_end_x)
	{
		texture_x = (int)((256 * (sprite->draw_start_x - (-sprite->width / 2 + sprite->screen_x)) * sprite->texture.width / sprite->width) / 256);
		if(sprite->transform_y > 0 && sprite->draw_start_x > 0 && sprite->draw_start_x < WINDOW_WIDTH && sprite->transform_y < data->z_buffer[sprite->draw_start_x])
		{
			y = sprite->draw_start_y - 1;
			while (++y < sprite->draw_end_y)
			{
				d = (y) * 256 - WINDOW_HEIGHT * 128 + sprite->height * 128; //256 and 128 factors to avoid floats
				texture_y = ((d * sprite->texture.height) / sprite->height) / 256;
				color = sprite->texture.addr[sprite->texture.width * texture_y + texture_x]; //get current color from the texture
       			if (color != 0)
      				put_pixel(&data->image, WINDOW_WIDTH - sprite->draw_start_x, y, color); //paint pixel if it isn't black, black is the invisible color
			}
		}
		sprite->draw_start_x++;
	}
}
