/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:01 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/03 12:03:12 by vsergio          ###   ########.fr       */
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