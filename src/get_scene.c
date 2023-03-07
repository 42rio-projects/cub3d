/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:21:19 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/07 16:00:46 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void get_scene_content(char *scene_filename, t_scene_info *scene);
void print_matrix(char **matrix);
int get_path(t_scene_info *scene, char *type);
void  assign_to_path(t_scene_info *scene, char *path, char *type);

void	get_scene(t_scene_info *scene, char *scene_filename)
{
	get_scene_content(scene_filename, scene);
}

void get_scene_content(char *scene_filename, t_scene_info *scene)
{
  char *scene_content = NULL;
  char *buffer = NULL;
  int scene_fd;

  // (void)scene;
	scene_fd = open(scene_filename, O_RDONLY, 0666);
  buffer = get_next_line(scene_fd);
  if (buffer)
  {
    scene_content = ft_strdup(buffer);
    free(buffer);
  }
  while(buffer)
  {
    buffer = get_next_line(scene_fd);
    if (buffer)
        scene_content = ft_strjoin_autofree(scene_content, buffer, 'a');
  }
  scene->raw_content = ft_split(scene_content, '\n');
  free(scene_content);
  print_matrix(scene->raw_content);
  get_path(scene, "NO");
  get_path(scene, "SO");
  get_path(scene, "WE");
  get_path(scene, "EA");
  printf("%s\n", scene->no_path);
  printf("%s\n", scene->so_path);
  printf("%s\n", scene->we_path);
  printf("%s\n", scene->ea_path);
}

int get_path(t_scene_info *scene, char *type)
{
  char **temp;
  int found;

  temp = scene->raw_content;
  found = 0;
  while(*temp)
  {
    if (!ft_strncmp(*temp, type, 2))
    {
      assign_to_path(scene, *temp, type);
      found++;
    }
    temp++;
  }
  if (found == 1)
    return (1);
  else
    return (0);
}

void  assign_to_path(t_scene_info *scene, char *path, char *type)
{
  if (!ft_strncmp(type, "NO", 3))
    scene->no_path = ft_strdup(path);
  else if (!ft_strncmp(type, "SO", 3))
    scene->so_path = ft_strdup(path);
  else if (!ft_strncmp(type, "WE", 3))
    scene->we_path = ft_strdup(path);
  else if (!ft_strncmp(type, "EA", 3))
    scene->ea_path = ft_strdup(path);
}

void print_matrix(char **matrix)
{
  while(*matrix)
  {
    printf("%s\n", *matrix);
    matrix++;
  }
}