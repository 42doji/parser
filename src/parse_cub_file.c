/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:21:13 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:21:14 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int  append_map_line(char ***map_lines, int *map_size, char *line, t_map *map)
{
    char    **temp;

    temp = malloc(sizeof(char *) * (*map_size + 2));
    if (!temp)
    {
        error_handler(MALLOC_ERROR, NULL, map);
        return (0);
    }
    if (*map_lines)
    {
        ft_memcpy(temp, *map_lines, sizeof(char *) * (*map_size));
        free(*map_lines);
    }
    *map_lines = temp;
    (*map_lines)[*map_size] = ft_strdup(line);
    if (!(*map_lines)[*map_size])
    {
        error_handler(MALLOC_ERROR, NULL, map);
        return (0);
    }
    (*map_lines)[*map_size + 1] = NULL;
    (*map_size)++;
    return (1);
}

static int validate_color_values(char **colors, t_color *color, t_map *map)
{
    int r, g, b;

    r = ft_atoi(colors[0]);
    g = ft_atoi(colors[1]);
    b = ft_atoi(colors[2]);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
    {
        free_split(colors);
        error_handler(COLOR_ERROR, NULL, map);
        return (0);
    }
    color->r = r;
    color->g = g;
    color->b = b;
    free_split(colors);
    return (1);
}

static int  parse_color(const char *line, t_color *color, t_map *map)
{
    char    **split;
    char    **colors;

    trim_line_endings((char *)line);
    split = ft_split(line, ' ');
    if (!split || !split[1] || split[2])
    {
        free_split(split);
        error_handler(COLOR_ERROR, NULL, map);
        return (0);
    }
    colors = ft_split(split[1], ',');
    free_split(split);
    if (!colors || ft_splitlen(colors) != 3)
    {
        free_split(colors);
        error_handler(COLOR_ERROR, NULL, map);
        return (0);
    }
    return (validate_color_values(colors, color, map));
}

int  parse_settings(const char *line, t_map *map)
{
    if (ft_strncmp(line, "NO ", 3) == 0)
        return (parse_texture(line, map, TEXTURE_NORTH));
    else if (ft_strncmp(line, "SO ", 3) == 0)
        return (parse_texture(line, map, TEXTURE_SOUTH));
    else if (ft_strncmp(line, "EA ", 3) == 0)
        return (parse_texture(line, map, TEXTURE_EAST));
    else if (ft_strncmp(line, "WE ", 3) == 0)
        return (parse_texture(line, map, TEXTURE_WEST));
    else if (ft_strncmp(line, "F ", 2) == 0)
        return (parse_color(line, &map->floor_color, map));
    else if (ft_strncmp(line, "C ", 2) == 0)
        return (parse_color(line, &map->ceiling_color, map));
    error_handler(TEXTURE_ERROR, NULL, map);
    return (0);
}

int  check_settings_complete(t_map *map)
{
    int i;

    i = 0;
    while (i < TEXTURE_COUNT)
    {
        if (!map->texture[i].path)
            return (0);
        i++;
    }
    if (map->floor_color.r == -1 || map->floor_color.g == -1 || map->floor_color.b == -1 ||
        map->ceiling_color.r == -1 || map->ceiling_color.g == -1 || map->ceiling_color.b == -1)
        return (0);
    return (1);
}
