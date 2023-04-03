/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:01 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/03 13:20:13 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_argc(argc))
		return (print_error(ARG_ERROR, 1));
	if (check_extention(argv[1], ".cub"))
		return (print_error(EXT_ERROR, 1));
	if (set_scene(&data, argv[1]))
		return (1);
	init_data(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_event, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

void	init_data(t_data *info)
{
	info->mlx_ptr = mlx_init();
	info->win = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	info->img = mlx_new_image(info->mlx_ptr, WIDTH, HEIGHT);
	info->addr = mlx_get_data_addr(info->img, &info->bpp, &info->line_len,
			&info->endian);
}