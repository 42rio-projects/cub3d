/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:11:50 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/12 22:20:15 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_file(int fd)
{
	char	*tmp;
	char	*file;
	char	buffer[4097];
	int		readed;

	if (fd == -1)
		return (NULL);
	file = ft_strdup("");
	readed = 4096;
	while (readed == 4096)
	{
		readed = read(fd, buffer, 4096);
		buffer[readed] = '\0';
		tmp = ft_strjoin(file, buffer);
		free(file);
		file = tmp;
	}
	return (file);
}
