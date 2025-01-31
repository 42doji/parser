#include "cub3d.h"

void	error_handler(t_error error)
{
	const char *error_msg[] = {
		"Error: No error",
		"Error: Memory allocation failed",
		"Error: Failed to open file",
		"Error: Failed to read file", 
		"Error: Invalid arguments",
		"Error: Invalid resolution",
		"Error: Invalid texture",
		"Error: Invalid color",
		"Error: Invalid map",
		"Error: Invalid file name",
		"Error: Invalid map walls",
		"Error: Invalid number of players",
		"Error: Invalid map characters",
		"Error: Map size is too small"
	};
	ft_putendl_fd((char *)error_msg[error], 2);
	exit(1);
}
