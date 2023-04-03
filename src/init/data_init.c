/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:12:00 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/03 18:16:35 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char** get_file_content(char const* file)
{
	char *file_content;
	int fd;
	char** split_content;

	fd = open(file, O_RDONLY);
	if (fd == -1) {
		throw_error(NULL);
		perror(file);
		return NULL;
	}
	file_content = read_file(fd);
	close(fd);
	if (validate_content(file_content)) {
		free(file_content);
		return NULL;
	}
	split_content = ft_split(file_content, '\n');
	free(file_content);
	return split_content;
}

void	set_null_scene(t_scene* scene)
{
	scene->map_grid = NULL;
	ft_memset(&scene->no_texture, 0, sizeof(t_texture));
	ft_memset(&scene->so_texture, 0, sizeof(t_texture));
	ft_memset(&scene->we_texture, 0, sizeof(t_texture));
	ft_memset(&scene->ea_texture, 0, sizeof(t_texture));
}

bool data_init(t_data *data, char const *file)
{
	char** file_content;

	file_content = get_file_content(file);
	if (file_content == NULL)
		return (1);
	data->mlx_ptr = mlx_init();
	set_null_scene(&data->scene);
	if (elements_init(data, file_content)) {
		free_matrix(file_content);
		free_scene(&data->scene);
		return (1);
	}
  if (map_init(&data->scene, file_content)) {
		free_matrix(file_content);
		free_scene(&data->scene);
		return (1);
	}
	// data->player = player_init(data->map);
	// if (data->player == NULL) {
	// 	free_matrix(file_content);
	// 	free_matrix(data->map->grid);
	// 	free(data->map);
	// 	free(data);
	// 	return 1;
	// }

	// //ponteiro da janela
	// data->mlx.win = mlx_new_window(data->mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");

	// // create a background image and put to window
	// data->background_image.img = mlx_new_image(data->mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	// data->background_image.addr = mlx_get_data_addr(data->background_image.img, &data->background_image.bpp, &data->background_image.size_len, &data->background_image.endian);
	// draw_background(&data->background_image, data->floor_color, data->ceil_color);
	// mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->background_image.img, 0, 0);

	// // creates the main image: player on minimap, rays and walls
	// data->image.img = mlx_new_image(data->mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	// data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bpp, &data->image.size_len, &data->image.endian);
	// draw_image(&data->image, data);
	// mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->image.img, 0, 0);
	// free_matrix(file_content);
	return (0);
}