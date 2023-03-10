/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:01 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/14 18:09:44 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	info;

	if (check_argc(argc))
		return (print_error(ARG_ERROR, 1));
	if (check_extention(argv[1], ".cub"))
		return (print_error(EXT_ERROR, 1));
	if (build_scene(&info.scene, argv[1]))
		return (1);
	init_data(&info);
	mlx_put_image_to_window(info.init, info.win, info.img, 0, 0);
	mlx_key_hook(info.win, key_event, &info);
	mlx_hook(info.win, 17, 0, close_win, &info);
	mlx_loop(info.init);
	return (0);
}

void	init_data(t_data *info)
{
	info->init = mlx_init();
	info->win = mlx_new_window(info->init, WIDTH, HEIGHT, "cub3d");
	info->img = mlx_new_image(info->init, WIDTH, HEIGHT);
	info->addr = mlx_get_data_addr(info->img, &info->bpp, &info->line_len,
			&info->endian);
}

t_data	square_img(int width, int height, int color, void *mlx)
{
	t_data	sqr;
	int		x;
	int		y;

	x = -1;
	sqr.img = mlx_new_image(mlx, width, height);
	sqr.addr = mlx_get_data_addr(sqr.img, &sqr.bpp, &sqr.line_len, &sqr.endian);
	while (++x < width)
	{
		y = -1;
		while (++y < height)
			my_mlx_pixel_put(&sqr, x, y, color);
	}	
	return (sqr);
}
