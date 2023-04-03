/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:05 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/03 17:44:10 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_extension(char const *file, char const *extension)
{
	size_t	extension_len;
	int		file_len;

	extension_len = ft_strlen(extension);
	file_len = ft_strlen(file) - extension_len;
	if (file_len < 0)
		return (1);
	if (ft_strncmp(file + file_len, extension, extension_len))
		return (1);
	return (0);
}
