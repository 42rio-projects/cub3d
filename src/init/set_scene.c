/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:12:00 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/03 15:38:56 by vsergio          ###   ########.fr       */
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

static int	validate_scene(t_data *data, char **file_content)
{
	if (texture_and_color_init(data, file_content))
		return (1);
	if (set_map(&data->scene, file_content))
		return (1);
	return (0);
}

int	set_scene(t_data *data, char *filename)
{
	char	**file_content;

	file_content = get_file_content(filename);
	if (file_content == NULL)
		return (1);
	if (validate_scene(data, file_content))
	{
		free_matrix(file_content);
		return (1);
	}
	free_matrix(file_content);
	return (0);
}
