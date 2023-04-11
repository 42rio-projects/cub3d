/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:48:42 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/10 21:36:58 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_scene(t_scene *scene)
{
	free_matrix(scene->map_grid);
	free(scene->d_texture.text);
	free(scene->d_texture.addr);
	free(scene->s1_texture.text);
	free(scene->s1_texture.addr);
	free(scene->no_texture.text);
	free(scene->no_texture.addr);
	free(scene->so_texture.text);
	free(scene->so_texture.addr);
	free(scene->we_texture.text);
	free(scene->we_texture.addr);
	free(scene->ea_texture.text);
	free(scene->ea_texture.addr);
}
