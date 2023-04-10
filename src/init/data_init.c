/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:12:00 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/10 14:29:26 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**get_file_content(const char *file)
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

static void	set_default_scene(t_scene *scene)
{
	ft_bzero(&scene->d_texture, sizeof(t_texture));
	ft_bzero(&scene->no_texture, sizeof(t_texture));
	ft_bzero(&scene->so_texture, sizeof(t_texture));
	ft_bzero(&scene->we_texture, sizeof(t_texture));
	ft_bzero(&scene->ea_texture, sizeof(t_texture));
	scene->ceil_color = -1;
	scene->floor_color = -1;
	scene->map_width = 0;
	scene->map_height = 0;
	scene->map_grid = NULL;
}

bool	data_init(t_data *data, const char *file)
{
	char	**file_content;

	file_content = get_file_content(file);
	if (file_content == NULL)
		return (1);
	data->mlx_ptr = mlx_init();
	set_default_scene(&data->scene);
	if (elements_init(data, file_content))
		return (free_matrix(file_content), free_scene(&data->scene), 1);
	if (map_init(&data->scene, file_content))
		return (free_matrix(file_content), free_scene(&data->scene), 1);
	if (player_init(&data->player, &data->scene))
		return (free_matrix(file_content), free_scene(&data->scene), 1);
	sprites_init(data);
	image_init(data);
	free_matrix(file_content);
	return (0);
}
