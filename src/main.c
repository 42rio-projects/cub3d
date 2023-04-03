/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:01 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/03 16:44:35 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int	key_pressed(int keycode, t_data *data);
int	key_released(int keycode, t_data *data);

int32_t main(int32_t argc, char **argv)
{
	t_data data;

	if (argc != 2)
		return (throw_error("Usage: ./cub3d <scene_file>\n"));
	if (check_extension(argv[1], ".cub"))
		return (throw_error("Invalid file extension\n"));
	if (data_init(&data, argv[1]) == 1)
		return (1);
	// mlx_hook(data.win, 2, 0, &key_pressed, &data);
	// mlx_hook(data.win, 3, 0, &key_released, &data);
	// mlx_loop_hook(data.mlx_ptr, hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}