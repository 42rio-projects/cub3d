/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:21:06 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/11 17:50:00 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	copy_grid(t_scene *scene, char **file_content)
{
	size_t	i;

	scene->map_grid = malloc(sizeof(char *) * (scene->map_height + 1));
	i = -1;
	while (++i < scene->map_height)
		scene->map_grid[i] = ft_strdup(file_content[i]);
	scene->map_grid[i] = NULL;
	if (validate_grid(scene->map_grid))
		return (1);
	return (0);
}

bool	map_init(t_scene *scene, char **file_content)
{
	uint32_t	tmp;

	while (is_map_line(*file_content) == false)
		file_content++;
	while (file_content[scene->map_height]
		&& file_content[scene->map_height][0] != '\n')
	{
		tmp = ft_strlen(file_content[scene->map_height]);
		if (tmp > scene->map_width)
			scene->map_width = tmp;
		scene->map_height++;
	}
	if (copy_grid(scene, file_content))
		return (1);
	return (0);
}
