/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:23:17 by vsergio           #+#    #+#             */
/*   Updated: 2023/02/14 23:25:21 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_event(int keycode, t_data *info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(info->init, info->win);
		exit(EXIT_FAILURE);
	}
	return (0);
}
