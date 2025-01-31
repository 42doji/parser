#include "cub3d.h"

int  parse_texture(const char *line, t_map *map, int texture_index)
{
	char    **split;
	char    *path;

	trim_line_endings((char *)line);
	split = ft_split(line, ' ');
	if (!split || !split[1] || split[2])
	{
		free_split(split);
		error_handler(TEXTURE_ERROR);
		return (0);
	}
	if (map->texture[texture_index].path)
	{
		free_split(split);
		free_map_resources(NULL, map);
		error_handler(TEXTURE_ERROR);
		return (0);
	}
	path = ft_strdup(split[1]);
	free_split(split);
	if (!path)
		return (error_handler(MALLOC_ERROR), 0);
	map->texture[texture_index].path = path;
	return (1);
}