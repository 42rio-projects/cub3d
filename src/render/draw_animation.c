/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:52:24 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/10 22:16:23 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_stripe(t_sprite *sprite, t_image *image, int x)
{
	int	y_stripe;
	int	factor;
	int	texture_y;
	int	color;

	y_stripe = sprite->draw_start_y - 1;
	while (++y_stripe < sprite->draw_end_y)
	{
		factor = (y_stripe) * 256 - WINDOW_HEIGHT * 128 + sprite->height * 128;
		texture_y = ((factor * sprite->texture->height) / sprite->height) / 256;
		color = sprite->texture->addr[sprite->texture->width * texture_y
			+ sprite->texture_x];
		if (color != 0)
			put_pixel(image, WINDOW_WIDTH - x, y_stripe, color);
	}
}

static bool	stripe_is_visible(t_sprite *sprite, double *wall_distances,
	int x_stripe)
{
	if (sprite->transform_y > 0 && x_stripe > 0
		&& x_stripe < WINDOW_WIDTH
		&& sprite->transform_y < wall_distances[x_stripe])
		return (true);
	return (false);
}

static void	draw_all_stripes(t_data *data, t_sprite *sprite, bool invert)
{
	int	x_stripe;

	x_stripe = sprite->draw_start_x - 1;
	while (++x_stripe < sprite->draw_end_x)
	{
		if (invert == true)
		{
			sprite->texture_x = (int)(256 * ((sprite->draw_end_x
							- x_stripe) - (-(sprite->width) / 2
							+ (sprite->draw_end_x - sprite->screen_x)))
					* sprite->texture->width / sprite->width) / 256;
		}
		else
		{
			sprite->texture_x = (int)(256 * (x_stripe
						- (-sprite->width / 2 + sprite->screen_x))
					* sprite->texture->width / sprite->width) / 256;
		}
		if (stripe_is_visible(sprite, data->wall_distances, x_stripe))
			draw_stripe(sprite, &data->image, x_stripe);
	}
}

static void	death_checker(t_data *data, t_sprite *sprite)
{
	if (sprite->distance <= 0.15)
	{
		printf("You died\n");
		mlx_destroy_window(data->mlx_ptr, data->win);
		free(data->image.img);
		free(data->image.addr);
		free_scene(&data->scene);
		free(data->sprites);
		exit(EXIT_SUCCESS);
	}
}

bool	draw_animation(t_data *data, t_sprite *sprites)
{
	uint32_t	i;

	i = -1;
	while (++i < data->sprites_len)
	{
		death_checker(data, &sprites[sprites[i].order]);
		spritecast(&sprites[sprites[i].order], &data->player);
		if (sprites[sprites[i].order].frames < 40)
		{
			draw_all_stripes(data, &sprites[sprites[i].order], false);
			sprites[sprites[i].order].frames++;
		}
		else
		{
			draw_all_stripes(data, &sprites[sprites[i].order], true);
			sprites[sprites[i].order].frames++;
			if (sprites[sprites[i].order].frames > 80)
				sprites[sprites[i].order].frames = 0;
		}
	}
	return (0);
}
