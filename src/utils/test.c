/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:11:57 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/13 11:12:24 by gguedes          ###   ########.fr       */
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

void	print_scene(t_scene *scene)
{
	printf("%s\n", scene->no_path);
	printf("%s\n", scene->so_path);
	printf("%s\n", scene->we_path);
	printf("%s\n", scene->ea_path);
	printf("%s\n", scene->floor_color);
	printf("%s\n", scene->ceiling_color);
	print_matrix(scene->map);
}
