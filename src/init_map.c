#include "../include/cub3d.h"

static t_map *create_map(void)
{
    t_map *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
    {
        error_handler(MALLOC_ERROR);
        return (NULL);
    }
    return (map);
}

static int init_map_values(t_map *map)
{
    int i;

    if (!map)
    {
        error_handler(MALLOC_ERROR);
        return (0);
    }
    i = 0;
    while (i < TEXTURE_COUNT)
    {
        map->texture[i] = NULL;
        i++;
    }
    map->floor_color[0] = -1;
    map->floor_color[1] = -1;
    map->floor_color[2] = -1;
    map->ceiling_color[0] = -1;
    map->ceiling_color[1] = -1;
    map->ceiling_color[2] = -1;
    map->width = -1;
    map->height = -1;
    map->grid = NULL;
    return (1);
}

static void print_map(t_map *map)
{
    int i;

    i = 0;
    while (map->grid[i])
    {
        printf("%s\n", map->grid[i]);
        i++;
    }
}

static int print_init_map(t_map *map)
{
    if (!map)
    {
        error_handler(MALLOC_ERROR);
        return (0);
    }
    printf("--------------------\n");
    printf("MAP INIT------------\n");
    printf("--------------------\n");
    printf("NO: %s\n", map->texture[NO] ? map->texture[NO] : "Not Loaded");
    printf("SO: %s\n", map->texture[SO] ? map->texture[SO] : "Not Loaded");
    printf("EA: %s\n", map->texture[EA] ? map->texture[EA] : "Not Loaded");
    printf("WE: %s\n", map->texture[WE] ? map->texture[WE] : "Not Loaded");
    printf("floor_color: %d, %d, %d\n", map->floor_color[0], map->floor_color[1], map->floor_color[2]);
    printf("ceiling_color: %d, %d, %d\n", map->ceiling_color[0], map->ceiling_color[1], map->ceiling_color[2]);
    printf("width: %d, height: %d.\n", map->width, map->height);
    print_map(map);
    printf("--------------------\n");
    printf("MAP INIT END--------\n");
    printf("--------------------\n");
    return (1);
}

t_map *init_map(char *file_name)
{
    t_map *map;

    map = create_map();
    if (!init_map_values(map))
        return (NULL);
    if (!parse_cub_file(file_name, map))
    {
        free_map_resources(map);
        return (NULL);
    }
    if (!print_init_map(map))
        return (NULL);
    return (map);
}
