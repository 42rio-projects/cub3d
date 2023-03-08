/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:21:19 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/08 16:02:20 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_matrix(char **matrix);
int	get_texture_paths(t_scene_info *scene);
int	get_map(t_scene_info *scene);
int is_map_line(char *line);

int	get_scene_content(t_scene_info *scene, char *scene_filename)
{
	char	*scene_content;
	char	*buffer;
	int		scene_fd;

	scene_content = NULL;
	buffer = NULL;
	scene_fd = open(scene_filename, O_RDONLY, 0666);
	buffer = get_next_line(scene_fd);
	if (!buffer)
	{
		printf("empty file\n");
		return (0);
	}
	scene_content = ft_strdup(buffer);
	while (buffer)
	{
	  free(buffer);
		buffer = get_next_line(scene_fd);
		if (buffer)
			scene_content = ft_strjoin_autofree(scene_content, buffer, 'f');
	}
  scene->raw_content = ft_split(scene_content, '\n');
  free(scene_content);
	if (!get_texture_paths(scene) || !get_map(scene))
	{
		printf("invalid scene!\n");
		return (0);
	}
	printf("%s\n", scene->no_path);
	printf("%s\n", scene->so_path);
	printf("%s\n", scene->we_path);
	printf("%s\n", scene->ea_path);
	printf("%s\n", scene->floor_color);
	printf("%s\n", scene->ceiling_color);
	print_matrix(scene->map);
	return (1);
}

int	get_map(t_scene_info *scene)
{
  char **temp;

  temp = scene->raw_content;
	while(*temp)
	{
		if (!is_map_line(*temp))
			temp++;
		else
			break;
	}
  scene->map = temp;
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

int	get_texture_paths(t_scene_info *scene)
{
	char	**temp;
	int paths_quantity[6];

	ft_memset(paths_quantity, 0, sizeof(int) * 4);
	temp = scene->raw_content;
	while (*temp)
	{
		if (!ft_strncmp(*temp, "NO", 2))
		{
			scene->no_path = ft_strdup(*temp);
			paths_quantity[0]++;
		}
		else if (!ft_strncmp(*temp, "SO", 2))
		{
			scene->so_path = ft_strdup(*temp);
			paths_quantity[1]++;
		}
		else if (!ft_strncmp(*temp, "WE", 2))
		{
			scene->we_path = ft_strdup(*temp);
			paths_quantity[2]++;
		}
		else if (!ft_strncmp(*temp, "EA", 2))
		{
			scene->ea_path = ft_strdup(*temp);
			paths_quantity[3]++;
		}
		else if (!ft_strncmp(*temp, "F", 1))
		{
			scene->floor_color = ft_strdup(*temp);
			paths_quantity[4]++;
		}
		else if (!ft_strncmp(*temp, "C", 1))
		{
			scene->ceiling_color = ft_strdup(*temp);
			paths_quantity[5]++;
		}
		temp++;
	}
	if (paths_quantity[0] == 1 && paths_quantity[1] == 1 && paths_quantity[2] == 1 && paths_quantity[3] == 1 && paths_quantity[4] == 1 && paths_quantity[5] == 1)
		return (1);
	else
		return (0);
}
void	print_matrix(char **matrix)
{
	while (*matrix)
	{
		printf("%s\n", *matrix);
		matrix++;
	}
}