/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:12:00 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/03 11:57:45 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char** get_file_content(char const* file)
{
	int fd = open(file, O_RDONLY);
	if (fd == -1) {
		ft_putstr_fd("cub3d: ", STDERR_FILENO);
		perror(file);
		return NULL;
	}
	char *file_content = read_file(fd);
	close(fd);

	if (validate_content(file_content)) {
		free(file_content);
		return NULL;
	}
	char** split_content = ft_split(file_content, '\n');
	free(file_content);
	return split_content;
}

static int	set_scene(t_scene *scene, char **raw_content)
{
	if (set_info(scene, raw_content))
		return (1);
	if (set_colors(scene))
		return (1);
	if (set_map(scene, raw_content))
		return (1);
	return (0);
}

int	build_scene(t_scene *scene, char *filename)
{
	char	**raw_content;

	ft_memset(scene, 0, sizeof(t_scene));
	raw_content = get_file_content(filename);
	if (raw_content == NULL)
		return (1);
	if (set_scene(scene, raw_content))
	{
		free_matrix(raw_content);
		free_scene(scene);
		return (1);
	}
	free_matrix(raw_content);
	return (0);
}
