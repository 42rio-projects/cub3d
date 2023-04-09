/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:15:42 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/09 02:26:25 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	load_texture(t_data *data, t_texture *texture,
	char *path, char *error_str)
{
	texture->text = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&texture->width, &texture->height);
	if (texture->text == NULL)
		return (throw_error(error_str));
	texture->addr = (int *)mlx_get_data_addr(texture->text,
			&texture->bpp, &texture->size_len, &texture->endian);
	return (0);
}
