/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:38:51 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/12 22:56:40 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_scene(t_scene_info *scene)
{
	free(scene->no_path);
	free(scene->so_path);
	free(scene->we_path);
	free(scene->ea_path);
	free(scene->floor_color);
	free(scene->ceiling_color);
	free_matrix(scene->map);
}
