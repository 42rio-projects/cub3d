/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:19:42 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/13 16:21:03 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int invalid_colors(char *colors)
{
	int commas;

	commas = 0;
	if (*colors == ',')
		return (1);
	while(*colors)
	{
		if (*colors == ',')
		{
			commas++;
			colors++;
		}
		if (!ft_isdigit(*colors))
			return (1);
		colors++;
	}
	if (commas != 2)
		return (1);
	return (0);
}

static int convert_rgb_to_int(char *colors)
{
	char *temp;
	int rgb;

	colors = ft_strtrim(colors, "\n ");
	temp = colors;
	rgb = 0;
	if (invalid_colors(colors))
		return (print_error("Invalid colors!\n", 1));
	rgb = ft_atoi(colors) << 16;
	while(*colors && ft_isdigit(*colors))
		colors++;
	rgb |= ft_atoi(++colors) << 8;
	while(*colors && ft_isdigit(*colors))
		colors++;
	rgb |= ft_atoi(++colors);
	free(temp);
	return (rgb);
}

static int	check_scene_line(t_scene *scene, char *line)
{
	if (!ft_strncmp(line, "NO ", 3) && scene->no_path == NULL)
		scene->no_path = ft_strtrim(line + 3, "\n ");
	else if (!ft_strncmp(line, "SO ", 3) && scene->so_path == NULL)
		scene->so_path = ft_strtrim(line + 3, "\n ");
	else if (!ft_strncmp(line, "WE ", 3) && scene->we_path == NULL)
		scene->we_path = ft_strtrim(line + 3, "\n ");
	else if (!ft_strncmp(line, "EA ", 3) && scene->ea_path == NULL)
		scene->ea_path = ft_strtrim(line + 3, "\n ");
	else if (!ft_strncmp(line, "F ", 2) && scene->floor_rgb == -1)
		scene->floor_rgb = convert_rgb_to_int(line + 2);
	else if (!ft_strncmp(line, "C ", 2) && scene->ceiling_rgb == -1)
		scene->ceiling_rgb = convert_rgb_to_int(line + 2);
	else
		return (1);
	return (0);
}

static int	set_info(t_scene *scene, char **raw_content)
{
	int	set;

	set = 0;
	while (*raw_content && set < 6)
	{
		if (*raw_content[0] != '\n')
		{
			if (check_scene_line(scene, *raw_content))
				return (print_error("Error\nInvalid scene!\n", 1));
			set++;
		}
		raw_content++;
	}
	if (set != 6)
		return (print_error("Error\nMissing scene information!\n", 1));
	return (0);
}

static int	set_map(t_scene *scene, char **raw_content)
{
	int	i;

	while (*raw_content && !is_map_line(*raw_content))
		raw_content++;
	if (*raw_content == NULL || *raw_content[0] == '\0')
		return (print_error("Error\nNo map found\n", 1));
	i = 0;
	while (raw_content[i] && is_map_line(raw_content[i]))
		i++;
	if (raw_content[i] != NULL)
		return (print_error("Error\nInvalid map\n", 1));
	scene->map = malloc(sizeof(char *) * (i + 1));
	scene->map[i] = NULL;
	while (--i >= 0)
		scene->map[i] = ft_strdup(raw_content[i]);
	return (0);
}

int	set_scene(t_scene *scene, char **raw_content)
{
	if (set_info(scene, raw_content))
		return (1);
	if (set_map(scene, raw_content))
		return (1);
	if (validate_map(scene->map))
		return (1);
	return (0);
}
