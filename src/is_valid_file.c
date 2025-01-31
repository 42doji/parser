#include "cub3d.h"

int	is_valid_file(char *file_name)
{
	int	fd;

	if (!file_name)
	{
		error_handler(FILE_NAME_ERROR);
		return (0);
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		error_handler(OPEN_ERROR);
		return (0);
	}
	close(fd);
	return (1);
}
