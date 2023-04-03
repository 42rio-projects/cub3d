/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:34:34 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/03 17:45:02 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	validate_content(char const *file_content)
{
	while (*file_content)
	{
		while (*file_content == '\n')
			file_content++;
		while (*file_content && ft_strchr(" 01NSWE", *file_content))
			file_content++;
		if (*file_content == '\n')
			break ;
		file_content = ft_strchr(file_content, '\n');
		if (file_content == NULL)
			return (throw_error("Scene has no map\n"));
	}
	while (*file_content)
	{
		file_content++;
		if (*file_content == '\n')
			break ;
		while (*file_content && ft_strchr(" 01NSWE", *file_content))
			file_content++;
		if (*file_content != '\0' && *file_content != '\n')
			break ;
	}
	while (*file_content == '\n')
		file_content++;
	if (*file_content != '\0')
		return (throw_error("Invalid map line\n"));
	return (0);
}
