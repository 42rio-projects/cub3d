/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_content_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:34:34 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/11 17:54:02 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static const char	*find_map_line(const char *file_content)
{
	while (*file_content)
	{
		while (*file_content == '\n')
			file_content++;
		while (*file_content && ft_strchr(" 012FNSWE", *file_content))
			file_content++;
		if (*file_content == '\n')
			break ;
		file_content = ft_strchr(file_content, '\n');
		if (file_content == NULL)
			return (NULL);
	}
	return (file_content);
}

bool	validate_content(const char *file_content)
{
	file_content = find_map_line(file_content);
	if (file_content == NULL)
		return (throw_error("Scene has no map\n"));
	while (*file_content)
	{
		file_content++;
		if (*file_content == '\n')
			break ;
		while (*file_content && ft_strchr(" 012FNSWE", *file_content))
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
