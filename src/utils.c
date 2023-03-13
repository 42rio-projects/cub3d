/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:27:10 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/12 22:58:44 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_matrix(char **matrix)
{
	char	**temp;

	temp = matrix;
	while (*temp)
	{
		printf("%s", *temp);
		temp++;
	}
}

void	free_matrix(char **matrix)
{
	int	i;

	if (matrix == NULL)
		return ;
	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	print_scene(t_scene_info *scene)
{
	printf("%s\n", scene->no_path);
	printf("%s\n", scene->so_path);
	printf("%s\n", scene->we_path);
	printf("%s\n", scene->ea_path);
	printf("%s\n", scene->floor_color);
	printf("%s\n", scene->ceiling_color);
	print_matrix(scene->map);
}
