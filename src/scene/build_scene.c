/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:12:00 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/13 16:03:00 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**get_raw_content(char *filename)
{
	int		fd;
	char	*full_file;
	char	**raw_content;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error("Error\nCould not open file\n", 1);
		return (NULL);
	}
	full_file = read_file(fd);
	raw_content = ft_split_fake(full_file, '\n');
	free(full_file);
	close(fd);
	return (raw_content);
}

int	build_scene(t_scene *scene, char *filename)
{
	char	**raw_content;

	ft_memset(scene, 0, sizeof(t_scene));
	scene->ceiling_rgb = -1;
	scene->floor_rgb = -1;
	raw_content = get_raw_content(filename);
	if (raw_content == NULL)
		return (1);
	if (set_scene(scene, raw_content))
	{
		free_scene(scene);
		return (1);
	}
	return (0);
}
