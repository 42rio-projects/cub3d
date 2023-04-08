/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:19:44 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/08 14:54:50 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_image *image, int x, int y, uint32_t color)
{
	char	*dst;

	dst = image->addr + (y * image->size_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}
