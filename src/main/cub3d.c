/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:01 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/14 22:19:23 by gguedes          ###   ########.fr       */
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
	quit_program(&info);
	return (0);
}
