/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:38:51 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/14 17:43:51 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_scene(t_scene *scene)
{
	free(scene->no_path);
	free(scene->so_path);
	free(scene->we_path);
	free(scene->ea_path);
	free(scene->floor_content);
	free(scene->ceiling_content);
	free_matrix(scene->map);
}
