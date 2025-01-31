#include "cub3d.h"

static int parse_texture(char *line, t_map *map, int texture_index)
{
    char **split;

    split = ft_split(line, ' ');
    if (!split || !split[1] || split[2])
    {
        free_split(split);
        return (error_handler(TEXTURE_ERROR), 0);
    }
    if (map->texture[texture_index])
    {
        free_split(split);
        return (error_handler(TEXTURE_ERROR), 0);
    }
    map->texture[texture_index] = ft_strdup(split[1]);
    free_split(split);
    if (!map->texture[texture_index])
        return (error_handler(MALLOC_ERROR), 0);
    return (1);
}

static int parse_color(char *line, int *color)
{
    char **split;
    char **colors;
    int i;

    split = ft_split(line, ' ');
    if (!split || !split[1] || split[2])
    {
        free_split(split);
        return (error_handler(COLOR_ERROR), 0);
    }
    colors = ft_split(split[1], ',');
    free_split(split);
    if (!colors || ft_splitlen(colors) != 3)
    {
        free_split(colors);
        return (error_handler(COLOR_ERROR), 0);
    }
    i = 0;
    while (i < 3)
    {
        color[i] = ft_atoi(colors[i]);
        if (color[i] < 0 || color[i] > 255)
        {
            free_split(colors);
            return (error_handler(COLOR_ERROR), 0);
        }
        i++;
    }
    free_split(colors);
    return (1);
}

static int parse_settings(char *line, t_map *map)
{
    if (ft_strncmp(line, "NO ", 3) == 0)
        return (parse_texture(line, map, NO));
    else if (ft_strncmp(line, "SO ", 3) == 0)
        return (parse_texture(line, map, SO));
    else if (ft_strncmp(line, "EA ", 3) == 0)
        return (parse_texture(line, map, EA));
    else if (ft_strncmp(line, "WE ", 3) == 0)
        return (parse_texture(line, map, WE));
    else if (ft_strncmp(line, "F ", 2) == 0)
        return (parse_color(line, map->floor_color));
    else if (ft_strncmp(line, "C ", 2) == 0)
        return (parse_color(line, map->ceiling_color));
    return (error_handler(TEXTURE_ERROR), 0);
}

static int check_settings_complete(t_map *map)
{
    int i;

    i = 0;
    while (i < TEXTURE_COUNT)
    {
        if (!map->texture[i])
            return (0);
        i++;
    }
    if (map->floor_color[0] == -1 || map->ceiling_color[0] == -1)
        return (0);
    return (1);
}

int parse_cub_file(char *file_name, t_map *map)
{
    int fd;
    char *line;
    char **map_lines;
    int map_size;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return (error_handler(OPEN_ERROR), 0);

    map_lines = NULL;
    map_size = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (ft_strlen(line) > 0)
        {
            if (!check_settings_complete(map))
            {
                if (!parse_settings(line, map))
                {
                    free(line);
                    close(fd);
                    return (0);
                }
            }
            else
            {
                char **temp = realloc(map_lines, sizeof(char *) * (map_size + 2));
                if (!temp)
                {
                    free(line);
                    close(fd);
                    free_split(map_lines);
                    return (error_handler(MALLOC_ERROR), 0);
                }
                map_lines = temp;
                map_lines[map_size] = ft_strdup(line);
                if (!map_lines[map_size])
                {
                    free(line);
                    close(fd);
                    free_split(map_lines);
                    return (error_handler(MALLOC_ERROR), 0);
                }
                map_size++;
                map_lines[map_size] = NULL;
            }
        }
        free(line);
    }
    close(fd);

    if (!parse_map(map_lines, map))
    {
        free_split(map_lines);
        return (0);
    }
    free_split(map_lines);
    return (1);
}
