/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:35:52 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/03 16:54:44 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool load_texture(t_data* data, t_texture* texture, char* path, char* error_str)
{
	texture->text = mlx_xpm_file_to_image(data->mlx_ptr, path, &texture->width, &texture->height);
	if (texture->text == NULL)
		return (throw_error(error_str));
	texture->addr = (int *)mlx_get_data_addr(texture->text, &texture->bpp, &texture->size_len, &texture->endian);
	return (0);
}

static bool str_to_uint_color(long* color, char* str)
{
	long rgb[3];

	if (validate_colors(str))
		return (throw_error("Invalid set of colors\n"));
	rgb[0] = ft_atol(str);
	while (*str && ft_isdigit(*str))
		str++;
	rgb[1] = ft_atol(++str);
	while (*str && ft_isdigit(*str))
		str++;
	rgb[2] = ft_atol(++str);
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255
	|| rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0)
		return (throw_error("Invalid color value (0 to 255)\n"));
	*color = (rgb[0] << 24);
	*color |= (rgb[1] << 16);
	*color |= (rgb[2] << 8);
	*color |= 255;
	return (0);
}

static bool set_elements(t_data* data, char* line)
{
	t_scene* scene;

	scene = &data->scene;
	if (ft_strncmp(line, "NO ", 3) == 0 && scene->no_texture.text == NULL)
		return load_texture(data, &scene->no_texture, line + 3, "Invalid NO path\n");
	else if (ft_strncmp(line, "SO ", 3) == 0 && scene->so_texture.text == NULL)
		return load_texture(data, &scene->so_texture, line + 3, "Invalid SO path\n");
	else if (ft_strncmp(line, "WE ", 3) == 0 && scene->we_texture.text == NULL)
		return load_texture(data, &scene->we_texture, line + 3, "Invalid WE path\n");
	else if (ft_strncmp(line, "EA ", 3) == 0 && scene->ea_texture.text == NULL)
		return load_texture(data, &scene->ea_texture, line + 3, "Invalid EA path\n");
	else if (ft_strncmp(line, "F ", 2) == 0 && scene->floor_color == -1)
		return str_to_uint_color(&scene->floor_color, line + 2);
	else if (ft_strncmp(line, "C ", 2) == 0 && scene->ceil_color == -1)
		return str_to_uint_color(&scene->ceil_color, line + 2);
	else
		return (throw_error("Invalid scene information\n"));
	return (0);
}

bool elements_init(t_data* data, char** file_content)
{
	t_scene* scene;

	scene = &data->scene;
	scene->floor_color = -1;
	scene->ceil_color = -1;
	for (uint32_t i = 0; file_content[i]; i++) {
		if (file_content[i][0] == '\n')
			continue ;
		if (is_map_line(file_content[i]))
			break ;
		if (set_elements(data, file_content[i]))
			return (free_scene(&data->scene), 1);
	}
	if (!scene->no_texture.text || !scene->so_texture.text || !scene->we_texture.text || !scene->ea_texture.text
	|| scene->floor_color == -1 || scene->ceil_color == -1)
		return (free_scene(&data->scene), throw_error("Missing scene information\n"));
	return (0);
}
