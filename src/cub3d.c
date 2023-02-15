/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:01 by vsergio           #+#    #+#             */
/*   Updated: 2023/02/14 23:15:07 by mpinna-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


// prototipos
t_data	square_img(int width, int height, int color, void *mlx);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

int	main(void)
{
	t_data	info;
	t_data	QUADRADO;

	init_data(&info);
	QUADRADO = square_img(30, 30, RED, info.init);
	mlx_put_image_to_window(info.init, info.win, QUADRADO.img, 350, 350);	
	mlx_loop(info.init);
}

void	init_data(t_data *info)
{
	info->init = mlx_init();
	info->win = mlx_new_window(info->init, WIDTH, HEIGHT, "cub3d");
	info->img = mlx_new_image(info->init, WIDTH, HEIGHT);
	info->addr = mlx_get_data_addr(info->img, &info->bpp, &info->line_len,
			&info->endian);
}


void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}

t_data	square_img(int width, int height, int color, void *mlx)
{
	t_data	sqr_image;
	int		x;
	int		y;

	x = -1;
	sqr_image.img = mlx_new_image(mlx, width, height);
	sqr_image.addr = mlx_get_data_addr(sqr_image.img, &sqr_image.bpp, &sqr_image.line_len, &sqr_image.endian);
	while (++x < width)
	{
		y = -1;
		while (++y < height)
			my_mlx_pixel_put(&sqr_image, x, y, color);
	}	
	return (sqr_image);
}
