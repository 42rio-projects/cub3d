/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:50:25 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/09 00:34:25 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	int		sprite_order[NUM_SPRITES];
	double	sprite_distance[NUM_SPRITES];
bool	load_texture(t_data *data, t_texture *texture,
	char *path, char *error_str);

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;

	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount - 1; j++)
		{
			if (orders[j].distance > orders[j + 1].distance)
			{
				tmp.distance = orders[j].distance;
				tmp.order = orders[j].order;
				orders[j].distance = orders[j + 1].distance;
				orders[j].order = orders[j + 1].order;
				orders[j + 1].distance = tmp.distance;
				orders[j + 1].order = tmp.order;
			}
		}
	}
}

void	sortSprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;

	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
	for (int i = 0; i < amount; i++)
	{
		sprites[i].distance = dist[i];
		sprites[i].order = order[i];
	}
	sort_order(sprites, amount);
	for (int i = 0; i < amount; i++)
	{
		dist[i] = sprites[amount - i - 1].distance;
		order[i] = sprites[amount - i - 1].order;
	}
	free(sprites);
}

void  set_sprites_pos(t_sprite* sprites)
{
  sprites[0].x = 3.5;
  sprites[0].y = 3.5;
  sprites[0].texture = 10;

  sprites[1].x = 4.5;
  sprites[1].y = 4.5;
  sprites[1].texture = 10;

  sprites[2].x = 2.5;
  sprites[2].y = 2.5;
  sprites[2].texture = 10;
}

void	sprite_casting(t_data *data)
{
  t_player *player;
  t_texture *sprite;
  t_sprite* test_sprites;


  player = &data->player;
  sprite = &data->scene.sprite;

  set_sprites_pos(data->sprites);
  test_sprites = data->sprites;
  load_texture(data, sprite, "./textures/xpm/barrel.xpm", "visao\n");

	//SPRITE CASTING
	//sort sprites from far to close
	for(int i = 0; i < NUM_SPRITES; i++)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((player->pos_x - test_sprites[i].x) * (player->pos_x - test_sprites[i].x) + (player->pos_y - test_sprites[i].y) * (player->pos_y - test_sprites[i].y)); //sqrt not taken, unneeded
	}
	sortSprites(sprite_order, sprite_distance, NUM_SPRITES);
	//after sorting the sprites, do the projection and draw them
	for(int i = 0; i < NUM_SPRITES; i++)
	{
		//translate sprite position to relative to camera
		double spriteX = test_sprites[sprite_order[i]].x - player->pos_x;
		double spriteY = test_sprites[sprite_order[i]].y - player->pos_y;

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		double invDet = 1.0 / (player->plane_x * player->dir_y - player->dir_x * player->plane_y); //required for correct matrix multiplication

		double transformX = invDet * (player->dir_y * spriteX - player->dir_x * spriteY);
		double transformY = invDet * (-player->plane_y * spriteX + player->plane_x * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])

		int spriteScreenX = (int)((WINDOW_WIDTH / 2) * (1 + transformX / transformY));

		//parameters for scaling and moving the sprites

		//calculate height of the sprite on screen
		int spriteHeight = (int)fabs((WINDOW_HEIGHT / transformY)); //using "transformY" instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + WINDOW_HEIGHT / 2;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + WINDOW_HEIGHT / 2;
		if(drawEndY >= WINDOW_HEIGHT) drawEndY = WINDOW_HEIGHT - 1;

		//calculate width of the sprite
		int spriteWidth = (int)fabs((WINDOW_HEIGHT / transformY));
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= WINDOW_WIDTH) drawEndX = WINDOW_WIDTH - 1;

		//loop through every vertical stripe of the sprite on screen
		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * sprite->width / spriteWidth) / 256);
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if(transformY > 0 && stripe > 0 && stripe < WINDOW_WIDTH && transformY < data->z_buffer[stripe])
			for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
			{
				int d = (y) * 256 - WINDOW_HEIGHT * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
				int texY = ((d * data->scene.so_texture.height) / spriteHeight) / 256;
				int color = sprite->addr[sprite->width * texY + texX]; //get current color from the texture
        if (color != 0)
          put_pixel(&data->image, WINDOW_WIDTH - stripe, y, color); //paint pixel if it isn't black, black is the invisible color
			}
		}
	}
}

void	raycast(t_data *data, t_player *player, t_scene *scene)
{
	t_ray		ray;
	double		camera_x;
	uint32_t	x;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
		ray.dir_x = player->dir_x + player->plane_x * camera_x;
		ray.dir_y = player->dir_y + player->plane_y * camera_x;
		cast(player, scene, &ray);
		data->z_buffer[x] = ray.distance;
		draw_vertical_line(data, player, &ray, x);
	}
  sprite_casting(data);
}
