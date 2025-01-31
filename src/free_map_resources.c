#include "cub3d.h"

void free_map_resources(t_map *map)
{
    int i;

    if (!map)
        return;
    
    i = 0;
    while (i < TEXTURE_COUNT)
    {
        if (map->texture[i])
            free(map->texture[i]);
        i++;
    }

    if (map->grid)
    {
        i = 0;
        while (i < map->height)
        {
            free(map->grid[i]);
            i++;
        }
        free(map->grid);
    }
    free(map);
}
