/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:19:44 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/11 17:50:48 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	put_pixel(t_image *image, int x, int y, uint32_t color)
{
	char	*dst;

	dst = image->addr + (y * image->size_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}
