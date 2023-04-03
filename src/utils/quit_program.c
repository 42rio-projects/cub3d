/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:21:00 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/03 13:16:12 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// may need more frees

void	quit_program(t_data *info)
{
	mlx_destroy_window(info->mlx_ptr, info->win);
	free_scene(&info->scene);
	exit(0);
}
