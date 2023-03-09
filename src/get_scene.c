/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:21:19 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/09 11:01:30 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_matrix(char **matrix);
int	get_texture_paths(t_scene_info *scene);
int	get_map(t_scene_info *scene);
int is_map_line(char *line);

int	get_scene_content(t_scene_info *scene, char *scene_filename)
{
	char	*inline_content;
	char	*buffer;
	int		scene_fd;

	scene_fd = open(scene_filename, O_RDONLY, 0666);
	buffer = get_next_line(scene_fd);
	if (!buffer)
	{
		free(buffer);
		print_error("empty file\n", 0);
	}
	inline_content = ft_strdup(buffer);
	while (buffer)
	{
	  free(buffer);
		buffer = get_next_line(scene_fd);
		if (buffer)
			inline_content = ft_strjoin_autofree(inline_content, buffer, 'f');
	}
  scene->matrix_content = ft_split(inline_content, '\n');
  free(inline_content);
	if (!get_texture_paths(scene) || !get_map(scene))
	{
		free_matrix(scene->matrix_content);
		print_error("invalid scene\n", 0);
	}
	print_scene(scene);
	return (1);
}

int	get_texture_paths(t_scene_info *scene)
{
	char	**temp;
	int paths_quantity[6];

	ft_memset(paths_quantity, 0, sizeof(int) * 6);
	temp = scene->matrix_content;
	while (*temp)
	{
		if (!ft_strncmp(*temp, "NO", 2))
		{
			scene->no_path = *temp;
			paths_quantity[0]++;
		}
		else if (!ft_strncmp(*temp, "SO", 2))
		{
			scene->so_path = *temp;
			paths_quantity[1]++;
		}
		else if (!ft_strncmp(*temp, "WE", 2))
		{
			scene->we_path = *temp;
			paths_quantity[2]++;
		}
		else if (!ft_strncmp(*temp, "EA", 2))
		{
			scene->ea_path = *temp;
			paths_quantity[3]++;
		}
		else if (!ft_strncmp(*temp, "F", 1))
		{
			scene->floor_color = *temp;
			paths_quantity[4]++;
		}
		else if (!ft_strncmp(*temp, "C", 1))
		{
			scene->ceiling_color = *temp;
			paths_quantity[5]++;
		}
		temp++;
	}
	if (paths_quantity[0] == 1 && paths_quantity[1] == 1 && paths_quantity[2] == 1 && paths_quantity[3] == 1 && paths_quantity[4] == 1 && paths_quantity[5] == 1)
		return (1);
	else
		return (0);
}

int	get_map(t_scene_info *scene)
{
	int map_lines;
	int map_index;
  char **temp;

	map_index = 0;
	map_lines = 0;
  temp = scene->matrix_content;
	while(*temp)
	{
		if (is_map_line(*temp))
			map_lines++;
		temp++;
	}
	printf("map lines: %i\n", map_lines);
  scene->map = malloc(sizeof(char *) * (map_lines + 1));
	temp = scene->matrix_content;
	while(*temp)
	{
		if (is_map_line(*temp))
			scene->map[map_index++] = ft_strdup(*temp);
		temp++;
	}
	scene->map[map_index] = NULL;
	return (1);
}

int is_map_line(char *line)
{
	char *temp;

	temp = line;
	while(*temp)
	{
		if (*temp != '0' && *temp != '1' && *temp != 'N' && *temp != 'S' && *temp != 'E' && *temp != 'W' && *temp != ' ')
			return (0);
		temp++;
	}
	return (1);
}