/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:19:49 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/03 16:47:33 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_map(t_scene *scene, char **raw_content)
{
	int	i;

	while (*raw_content && !is_map_line(*raw_content))
		raw_content++;
	if (*raw_content == NULL || *raw_content[0] == '\0')
		return (throw_error("No map found\n"));
	i = 0;
	while (raw_content[i] && is_map_line(raw_content[i]))
		i++;
	if (raw_content[i] != NULL)
		return (throw_error("Invalid map line\n"));
	scene->map = malloc(sizeof(char *) * (i + 1));
	scene->map[i] = NULL;
	while (--i >= 0)
		scene->map[i] = ft_strtrim(raw_content[i], "\n");
	if (validate_map(scene->map))
		return (1);
	return (0);
}
