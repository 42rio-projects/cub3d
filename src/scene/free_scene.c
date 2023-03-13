/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:38:51 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/13 16:03:10 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_scene(t_scene *scene)
{
	free(scene->no_path);
	free(scene->so_path);
	free(scene->we_path);
	free(scene->ea_path);
	free_matrix(scene->map);
}
