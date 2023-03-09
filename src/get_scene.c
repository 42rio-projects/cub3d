/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:21:19 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/09 15:56:36 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_matrix(char **matrix);
int	get_texture_paths(t_scene_info *scene);
int	get_map(t_scene_info *scene);
int is_map_line(char *line);
void get_matrix_content(t_scene_info *scene, int matrix_size, char *scene_filename);
int get_matrix_size(char *scene_filename);

int	get_scene_content(t_scene_info *scene, char *scene_filename)
{
	int 	matrix_size;

	matrix_size = get_matrix_size(scene_filename);
	get_matrix_content(scene, matrix_size, scene_filename);
	if (!get_texture_paths(scene) || !get_map(scene))
	{
		free_matrix(scene->matrix_content);
		print_error("invalid scene\n", 0);
	}
	print_scene(scene);
	return (1);
}

int get_matrix_size(char *scene_filename)
{
	int scene_fd;
	char *buffer;
	int size;

	size = 0;
	scene_fd = open(scene_filename, O_RDONLY, 0666);
	buffer = get_next_line(scene_fd);
	if (!buffer)
	{
		free(buffer);
		print_error("empty file\n", 0);
	}
	size++;
	while (buffer)
	{
	  free(buffer);
		buffer = get_next_line(scene_fd);
		if (buffer)
			size++;
	}
	close(scene_fd);
	return (size);
}

void get_matrix_content(t_scene_info *scene, int matrix_size, char *scene_filename)
{
	int		scene_fd;
	int 	m_index;
	char	*buffer;

	scene_fd = open(scene_filename, O_RDONLY, 0666);
	buffer = get_next_line(scene_fd);
	m_index = 0;
	scene->matrix_content = malloc(sizeof(char *) * (matrix_size + 1));
	scene->matrix_content[m_index++] = ft_strdup(buffer);
	while(buffer)
	{
		free(buffer);
		buffer = get_next_line(scene_fd);
		if (buffer)
			scene->matrix_content[m_index++] = ft_strdup(buffer);
	}
	scene->matrix_content[m_index] = NULL;
	close(scene_fd);
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
	int start_map;
	int end_map;
	int map_lines;
	int m_index;

	start_map = 0;
	end_map = 0;
	map_lines = 0;
	m_index = 0;
	while(scene->matrix_content[start_map])
	{
		if (is_map_line(scene->matrix_content[start_map]))
			break;
		start_map++;
	}
	end_map = start_map;
	while(scene->matrix_content[end_map])
	{
		if (is_map_line(scene->matrix_content[end_map]))
			map_lines++;
		else
			break;
		end_map++;
	}
  scene->map = malloc(sizeof(char *) * (map_lines + 1));
	while(start_map < end_map)
		scene->map[m_index++] = ft_strdup(scene->matrix_content[start_map++]);
	//map must be freed in the end
	scene->map[m_index] = NULL;
	return (1);
}

int is_map_line(char *line)
{
	char *temp;

	temp = line;
	if (*temp == '\n')
		return (0);
	while(*temp)
	{
		if (*temp != '0' && *temp != '1' && *temp != 'N' && *temp != 'S' && *temp != 'E' && *temp != 'W' && *temp != ' ' && *temp != '\n')
			return (0);
		temp++;
	}
	return (1);
}