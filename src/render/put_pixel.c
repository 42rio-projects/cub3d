/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:19:44 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/04 16:20:29 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_data *data, int x, int y, uint32_t color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
