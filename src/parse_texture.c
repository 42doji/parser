#include "cub3d.h"

int  parse_texture(const char *line, t_map *map, int texture_index, const char *key, t_game *game)
{
    char    **split;
    char    *path;

    trim_line_endings((char *)line);
    split = ft_split(line, ' ');
    if (!split || !split[1] || split[2])
    {
        free_split(split);
        error_handler(TEXTURE_ERROR, game, map);
        return (0);
    }
    if (map->texture[texture_index].path)
    {
        free_split(split);
        ft_putstr_fd("Error: Duplicate key '", 2);
        ft_putstr_fd(key, 2);
        ft_putendl_fd("'", 2);
        error_handler(DUPLICATE_KEY_ERROR, game, map);
        return (0);
    }
    path = ft_strdup(split[1]);
    free_split(split);
    if (!path)
    {
        error_handler(MALLOC_ERROR, game, map);
        return (0);
    }
    map->texture[texture_index].path = path;
    return (1);
}
