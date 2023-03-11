/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:21:19 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/11 13:46:51 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_matrix(char **matrix);
int	get_texture_paths(t_scene_info *scene);
int	get_map(t_scene_info *scene);
int is_map_line(char *line);
void get_raw_content(t_scene_info *scene, char *scene_filename);

int	get_scene_content(t_scene_info *scene, char *scene_filename)
{
	get_raw_content(scene, scene_filename);
	if (!get_texture_paths(scene) || !get_map(scene))
	{
		// free_matrix(scene->matrix_content);
		print_error("invalid scene\n", 0);
	}
	print_scene(scene);
	return (1);
}

void get_raw_content(t_scene_info *scene, char *scene_filename)
{
	char	buffer[4097];
	char *content;
	int		scene_fd;
	int readed;

	readed = 4096;
	content = ft_strdup("");
	scene_fd = open(scene_filename, O_RDONLY, 0666);
	if (scene_fd == -1)
		print_error("Invalid file", 0);
	while(readed == 4096)
	{
		readed = read(scene_fd, buffer, 4096);
		buffer[readed] = '\0';
		if (readed >= 1)
			content = ft_strjoin_autofree(content, buffer, 'f');
	}
	scene->raw_content = ft_split(content, '\n');
	close(scene_fd);
}

int	get_texture_paths(t_scene_info *scene)
{
	char **temp;
	int paths_quantity[6];

	ft_memset(paths_quantity, 0, sizeof(int) * 6);
	temp = scene->raw_content;
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
	int start_map;
	int end_map;
	int map_lines;
	int map_index;

	start_map = 0;
	map_lines = 0;
	map_index = 0;
	while(scene->raw_content[start_map])
	{
		if (is_map_line(scene->raw_content[start_map]))
			break;
		start_map++;
	}
	end_map = start_map;
	while(scene->raw_content[end_map])
	{
		if (is_map_line(scene->raw_content[end_map]))
			map_lines++;
		else
			break;
		end_map++;
	}
  scene->map = malloc(sizeof(char *) * (map_lines + 1));
	while(map_index < map_lines)
	{
		scene->map[map_index] = ft_strdup(scene->raw_content[start_map]);
		map_index++;
		start_map++;
	}
	return (1);
}

int is_map_line(char *line)
{
	if (*line == '\n')
		return (0);
	while(*line)
	{
		if (*line != '0' && *line != '1' && *line != 'N' && *line != 'S' && *line != 'E' && *line != 'W' && *line != ' ' && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}
