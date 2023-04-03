/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:21:00 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/14 18:10:57 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// may need more frees

void	quit_program(t_data *info)
{
	mlx_destroy_window(info->init, info->win);
	free_scene(&info->scene);
	exit(0);
}
