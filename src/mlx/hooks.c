/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:23:17 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/03 16:23:38 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_event(int keycode, t_data *info)
{
	(void)info;
	//TODO: Must free and exit program when press Escape
	if (keycode == 53)
		return (1);
	return (0);
}
