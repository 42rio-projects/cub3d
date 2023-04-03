/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:21:00 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/03 16:19:38 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// may need more frees

void	quit_program(t_data *info)
{
	mlx_destroy_window(info->mlx_ptr, info->win);
	free_matrix(info->scene.map);
	exit(0);
}
