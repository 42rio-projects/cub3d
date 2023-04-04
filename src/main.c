/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:01 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/04 18:38:46 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (throw_error("Usage: ./cub3d <scene_file>\n"));
	if (check_extension(argv[1], ".cub"))
		return (throw_error("Invalid file extension\n"));
	if (data_init(&data, argv[1]))
		return (1);
	// mlx_hook(data.win, 2, 0, &key_pressed, &data);
	// mlx_hook(data.win, 3, 0, &key_released, &data);
	// mlx_loop_hook(data.mlx_ptr, hook, &data);
	// mlx_loop(data.mlx_ptr);
	return (0);
}
