/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:11:57 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/20 16:10:34 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_matrix(char **matrix)
{
	char	**temp;

	temp = matrix;
	while (*temp)
	{
		printf("%s\n", *temp);
		temp++;
	}
}

void	print_scene(t_scene *scene)
{
	printf("%s\n", scene->no_path);
	printf("%s\n", scene->so_path);
	printf("%s\n", scene->we_path);
	printf("%s\n", scene->ea_path);
	print_matrix(scene->map);
}
