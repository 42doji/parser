#include <stdlib.h>

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_map *map;

	(void) argc;
	(void) argv;
	map = init_map();
	if (!map)
		return (EXIT_FAILURE);
	free(map);
	return (0);
}
