#include "cub3d.h"

//nao esta validando 100% a cena, porem valida se existe mapa, se toda linha eh composta por caracteres de mapa,
//se ele esta por ultimo e nao esta quebrado no meio
//apos isso, ainda havera outras validacoes como por exemplo se existe cor e textura na cena.
bool validate_content(char const* file_content)
{
	// iterate file_content until map line is found
	while (*file_content) {
		while (*file_content == '\n')
			file_content++;
		while (*file_content && ft_strchr(" 01NSWE", *file_content))
			file_content++;
		if (*file_content == '\n')
			break ; // map line found
		file_content = ft_strchr(file_content, '\n');
		if (file_content == NULL) { // found EOF and no map
			ft_putstr_fd("cub3d: Scene has no map\n", STDERR_FILENO);
			return 1;
		}
	}

	// iterate map lines until find a non map line
	while (*file_content) {
		file_content++;
		if (*file_content == '\n')
			break ; // found an empty line
		while (*file_content && ft_strchr(" 01NSWE", *file_content))
			file_content++;
		if (*file_content != '\0' && *file_content != '\n')
			break ; // found a non map line or the EOF
	}

	// all subsequent lines should be empty
	while (*file_content == '\n')
		file_content++;
	if (*file_content != '\0') {
		ft_putstr_fd("cub3d: Invalid map line\n", STDERR_FILENO);
		return 1;
	}
	return 0;
}
