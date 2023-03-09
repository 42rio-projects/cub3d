/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:21:19 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/09 16:37:47 by vsergio          ###   ########.fr       */
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
	char	*buffer;
	int		scene_fd;

	scene_fd = open(scene_filename, O_RDONLY, 0666);
	buffer = get_next_line(scene_fd);
	if (!buffer)
	{
		print_error("Empty file!", 0);
		return ;
	}
	scene->raw_size = 0;
	ft_lstadd_back(&scene->raw_content, ft_lstnew(buffer));
	scene->raw_size++;
	while(buffer)
	{
		buffer = get_next_line(scene_fd);
		if (buffer)
		{
			ft_lstadd_back(&scene->raw_content, ft_lstnew(buffer));
			scene->raw_size++;
		}
	}
	close(scene_fd);
}

int	get_texture_paths(t_scene_info *scene)
{
	t_list	*temp;
	int paths_quantity[6];

	ft_memset(paths_quantity, 0, sizeof(int) * 6);
	temp = scene->raw_content;
	while (temp)
	{
		if (!ft_strncmp(temp->content, "NO", 2))
		{
			scene->no_path = temp->content;
			paths_quantity[0]++;
		}
		else if (!ft_strncmp(temp->content, "SO", 2))
		{
			scene->so_path = temp->content;
			paths_quantity[1]++;
		}
		else if (!ft_strncmp(temp->content, "WE", 2))
		{
			scene->we_path = temp->content;
			paths_quantity[2]++;
		}
		else if (!ft_strncmp(temp->content, "EA", 2))
		{
			scene->ea_path = temp->content;
			paths_quantity[3]++;
		}
		else if (!ft_strncmp(temp->content, "F", 1))
		{
			scene->floor_color = temp->content;
			paths_quantity[4]++;
		}
		else if (!ft_strncmp(temp->content, "C", 1))
		{
			scene->ceiling_color = temp->content;
			paths_quantity[5]++;
		}
		temp = temp->next;
	}
	if (paths_quantity[0] == 1 && paths_quantity[1] == 1 && paths_quantity[2] == 1 && paths_quantity[3] == 1 && paths_quantity[4] == 1 && paths_quantity[5] == 1)
		return (1);
	else
		return (0);
}

int	get_map(t_scene_info *scene)
{
	t_list *start_map;
	t_list *end_map;
	int map_lines;
	int map_index;

	start_map = scene->raw_content;
	map_lines = 0;
	map_index = 0;
	while(start_map)
	{
		if (is_map_line(start_map->content))
			break;
		start_map = start_map->next;
	}
	end_map = start_map;
	while(end_map)
	{
		if (is_map_line(end_map->content))
			map_lines++;
		else
			break;
		end_map = end_map->next;
	}
  scene->map = malloc(sizeof(char *) * (map_lines + 1));
	while(map_index < map_lines)
	{
		scene->map[map_index] = ft_strdup(start_map->content);
		map_index++;
		start_map = start_map->next;
	}
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