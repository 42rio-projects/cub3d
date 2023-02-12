#include "../includes/cub3d.h"

int	check_argc(int argc)
{
	if (argc != 2)
	{
		errno = 22;
		perror(NULL);
		return (1);
	}
	return (0);
}
