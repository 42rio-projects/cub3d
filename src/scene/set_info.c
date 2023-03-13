/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:19:42 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/13 18:20:47 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	else if (!ft_strncmp(line, "F ", 2) && scene->floor_content == NULL)
		scene->floor_content = ft_strtrim(line + 2, "\n ");
	else if (!ft_strncmp(line, "C ", 2) && scene->ceiling_content == NULL)
		scene->ceiling_content = ft_strtrim(line + 2, "\n ");
	else
		return (1);
	return (0);
}

int	set_info(t_scene *scene, char **raw_content)
{
	int	set;

	set = 0;
	while (*raw_content && set < 6)
	{
		if (*raw_content[0] != '\n')
		{
			if (check_scene_line(scene, *raw_content))
				return (print_error("Error\nInvalid paths or color!\n", 1));
			set++;
		}
		raw_content++;
	}
	if (set != 6)
		return (print_error("Error\nMissing paths or color information!\n", 1));
	return (0);
}
