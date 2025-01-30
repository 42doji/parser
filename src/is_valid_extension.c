#include "cub3d.h"

int	is_valid_extension(char *file_name, char *extension)
{
	int		file_name_len;
	int		extension_len;
	char	*dot_pos;

	if (!file_name || !extension)
		return (0);
	file_name_len = ft_strlen(file_name);
	extension_len = ft_strlen(extension);
	if (file_name_len <= extension_len)
		return (0);
	dot_pos = ft_strrchr(file_name, '.');
	if (!dot_pos)
		return (0);
	return (ft_strncmp(dot_pos, extension, extension_len) == 0);
}
