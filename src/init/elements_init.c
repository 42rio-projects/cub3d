/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:35:52 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/10 14:29:31 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	str_to_uint_color(long *color, char *str)
{
	long	rgb[3];

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
	*color = rgb[0] << 16;
	*color |= rgb[1] << 8;
	*color |= rgb[2];
	return (0);
}

static bool	set_elements(t_data *data, char *line)
{
	t_scene	*scene;

	scene = &data->scene;
	if (ft_strncmp(line, "D ", 2) == 0 && scene->d_texture.text == NULL)
		return (load_texture(data,
				&scene->d_texture, line + 2, "Invalid D path\n"));
	else if (ft_strncmp(line, "NO ", 3) == 0 && scene->no_texture.text == NULL)
		return (load_texture(data,
				&scene->no_texture, line + 3, "Invalid NO path\n"));
	else if (ft_strncmp(line, "SO ", 3) == 0 && scene->so_texture.text == NULL)
		return (load_texture(data,
				&scene->so_texture, line + 3, "Invalid SO path\n"));
	else if (ft_strncmp(line, "WE ", 3) == 0 && scene->we_texture.text == NULL)
		return (load_texture(data,
				&scene->we_texture, line + 3, "Invalid WE path\n"));
	else if (ft_strncmp(line, "EA ", 3) == 0 && scene->ea_texture.text == NULL)
		return (load_texture(data,
				&scene->ea_texture, line + 3, "Invalid EA path\n"));
	else if (ft_strncmp(line, "F ", 2) == 0 && scene->floor_color == -1)
		return (str_to_uint_color(&scene->floor_color, line + 2));
	else if (ft_strncmp(line, "C ", 2) == 0 && scene->ceil_color == -1)
		return (str_to_uint_color(&scene->ceil_color, line + 2));
	else
		return (throw_error("Invalid scene information\n"));
	return (0);
}

bool	elements_init(t_data *data, char **file_content)
{
	uint32_t	i;
	t_scene		*scene;

	scene = &data->scene;
	i = -1;
	while (file_content[++i])
	{
		if (file_content[i][0] == '\n')
			continue ;
		if (is_map_line(file_content[i]))
			break ;
		if (set_elements(data, file_content[i]))
			return (1);
	}
	if (!scene->d_texture.text || !scene->no_texture.text
		|| !scene->so_texture.text || !scene->we_texture.text
		|| !scene->ea_texture.text
		|| scene->floor_color == -1 || scene->ceil_color == -1)
		return (throw_error("Missing scene information\n"));
	return (0);
}
