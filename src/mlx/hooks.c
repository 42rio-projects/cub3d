/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:23:17 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/14 17:44:33 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_event(int keycode, t_data *info)
{
	if (keycode == 53)
		quit_program(info);
	return (0);
}

int	close_win(t_data *info)
{
	quit_program(info);
	return (0);
}
