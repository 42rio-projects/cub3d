/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:11:50 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/11 17:53:46 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
