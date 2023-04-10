/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:13:25 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/09 21:45:58 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int animation = 0;

static void	draw_sprite_stripe(t_sprite* sprite, t_image* image, t_texture *texture, int x)
{
	int stripe;
	int factor;
	int	texture_y;
	int	color;
	stripe = sprite->draw_start_y - 1;
	//render the entire stripe from top to down
	while (++stripe < sprite->draw_end_y)
	{
		factor = (stripe) * 256 - WINDOW_HEIGHT * 128 + sprite->height * 128; //256 and 128 factors to avoid floats
		texture_y = ((factor * texture->height) / sprite->height) / 256;
		color = texture->addr[texture->width * texture_y + sprite->texture_x]; //get current color from the texture
		if (color != 0)
			put_pixel(image, WINDOW_WIDTH - x, stripe, color); //paint pixel if it isn't black, black is the invisible color
	}
}

// static void	draw_inverse_direction(t_data* data, t_sprite* sprite, t_texture *texture)
// {
// 	int	x;

// 	x = sprite->draw_start_x - 1;
// 	//loop through every vertical stripe of the sprite on screen
// 	while (++x < sprite->draw_end_x)
// 	{
// 		sprite->texture_x = (int)(256 * ((sprite->draw_end_x - x) - (-(sprite->width) / 2 + (sprite->draw_end_x - sprite->screen_x))) * sprite->texture[0].width / sprite->width) / 256;
// 		if(sprite->transform_y > 0 && x > 0 && x < WINDOW_WIDTH && sprite->transform_y < data->z_buffer[x])
// 			draw_sprite_stripe(sprite, &data->image, texture, x);
// 		x++;
// 	}
// }

static void	draw_right_direction(t_data* data, t_sprite* sprite, t_texture *texture)
{
	int	x;

	x = sprite->draw_start_x - 1;
	while (++x < sprite->draw_end_x)
	{
		sprite->texture_x = (int)(256 * (x - (-sprite->width / 2 + sprite->screen_x)) * texture->width / sprite->width) / 256;
		if(sprite->transform_y > 0 && x > 0 && x < WINDOW_WIDTH && sprite->transform_y < data->z_buffer[x])
			draw_sprite_stripe(sprite, &data->image, texture, x);
		x++;
	}
}

void	spritecast(t_sprite *sprite, t_player *player, t_data *data)
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
	if (animation < 40)
	{
		printf("1\n");
		draw_right_direction(data, sprite, &sprite->texture[0]);
		animation++;
	}
	else if (animation >= 40 && animation <= 80)
	{
		printf("2\n");
		draw_right_direction(data, sprite, &sprite->texture[1]);
		animation++;
	}
	else
	{
		printf("3\n");
		draw_right_direction(data, sprite, &sprite->texture[2]);
		animation++;
		if (animation > 120)
			animation = 0;
	}
}
