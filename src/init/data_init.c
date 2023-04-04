/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:12:00 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/04 17:44:27 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**get_file_content(char const *file)
{
	int		fd;
	char	*file_content;
	char	**split_content;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (throw_error(NULL), perror(file), NULL);
	file_content = read_file(fd);
	close(fd);
	if (validate_content(file_content))
		return (free(file_content), NULL);
	split_content = ft_split(file_content, '\n');
	free(file_content);
	return (split_content);
}

static void	set_null_scene(t_scene *scene)
{
	scene->map_grid = NULL;
	ft_memset(&scene->no_texture, 0, sizeof(t_texture));
	ft_memset(&scene->so_texture, 0, sizeof(t_texture));
	ft_memset(&scene->we_texture, 0, sizeof(t_texture));
	ft_memset(&scene->ea_texture, 0, sizeof(t_texture));
}

bool	data_init(t_data *data, char const *file)
{
	char	**file_content;

	file_content = get_file_content(file);
	if (file_content == NULL)
		return (1);
	set_null_scene(&data->scene);
	if (elements_init(data, file_content))
		return (free_matrix(file_content), free_scene(&data->scene), 1);
	if (map_init(&data->scene, file_content))
		return (free_matrix(file_content), free_scene(&data->scene), 1);
	if (player_init(&data->player, &data->scene))
    return (free_matrix(file_content), free_scene(&data->scene), 1);
	images_init(data);
	free_matrix(file_content);
	return (0);
}