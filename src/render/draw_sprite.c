/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:12:09 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/10 01:43:12 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_stripes(t_sprite *sprite, t_image *image, int x)
{
	int	stripe;
	int	factor;
	int	texture_y;
	int	color;

	stripe = sprite->draw_start_y - 1;
	//render the entire stripe from top to down
	while (++stripe < sprite->draw_end_y)
	{
		factor = (stripe) * 256 - WINDOW_HEIGHT * 128 + sprite->height * 128; //256 and 128 factors to avoid floats
		texture_y = ((factor * sprite->textures.height) / sprite->height) / 256;
		color = sprite->textures.addr[sprite->textures.width * texture_y + sprite->texture_x]; //get current color from the texture
		if (color != 0)
			put_pixel(image, WINDOW_WIDTH - x, stripe, color); //paint pixel if it isn't black, black is the invisible color
	}
}

static void	draw_entire_sprite(t_data *data, t_sprite *sprite, bool invert)
{
	while (sprite->draw_start_x < sprite->draw_end_x)
	{
		if (invert == true)
			sprite->texture_x = (int)(256 * ((sprite->draw_end_x - sprite->draw_start_x) - (-(sprite->width) / 2 + (sprite->draw_end_x - sprite->screen_x))) * sprite->textures.width / sprite->width) / 256;
		else
			sprite->texture_x = (int)(256 * (sprite->draw_start_x - (-sprite->width / 2 + sprite->screen_x)) * sprite->textures.width / sprite->width) / 256;
		if (sprite->transform_y > 0 && sprite->draw_start_x > 0 && sprite->draw_start_x < WINDOW_WIDTH && sprite->transform_y < data->z_buffer[sprite->draw_start_x])
			draw_stripes(sprite, &data->image, sprite->draw_start_x);
		sprite->draw_start_x++;
	}
}

void	draw_sprite(t_data *data, t_sprite *sprites)
{
	int	i;

	i = -1;
	while (++i < NUM_SPRITES)
	{
		spritecast(&sprites[sprites[i].order], &data->player);
		if (sprites[sprites[i].order].frames < 40)
		{
			draw_entire_sprite(data, &sprites[sprites[i].order], false);
			sprites[sprites[i].order].frames++;
		}
		else
		{
			draw_entire_sprite(data, &sprites[sprites[i].order], true);
			sprites[sprites[i].order].frames++;
			if (sprites[sprites[i].order].frames > 80)
				sprites[sprites[i].order].frames = 0;
		}
	}
}
