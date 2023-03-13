/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:12:00 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/12 22:52:48 by gguedes          ###   ########.fr       */
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
	raw_content = ft_split(full_file, '\n');
	free(full_file);
	close(fd);
	return (raw_content);
}

int	get_scene(t_scene_info *scene, char *filename)
{
	char	**raw_content;

	ft_memset(scene, 0, sizeof(t_scene_info));
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
