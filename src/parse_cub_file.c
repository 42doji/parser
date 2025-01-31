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

 static int  append_map_line(char ***map_lines, int *map_size, char *line)
 {
     char    **temp;

     temp = realloc(*map_lines, sizeof(char *) * (*map_size + 2));
     if (!temp)
         return (error_handler(MALLOC_ERROR), 0);
     *map_lines = temp;
     (*map_lines)[*map_size] = ft_strdup(line);
     if (!(*map_lines)[*map_size])
         return (error_handler(MALLOC_ERROR), 0);
     (*map_lines)[*map_size + 1] = NULL;
     (*map_size)++;
     return (1);
 }

 static void trim_line_endings(char *line)
 {
     size_t  len;

     len = ft_strlen(line);
     while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
     {
         line[len - 1] = '\0';
         len--;
     }
 }

 static int  parse_texture(char *line, t_map *map, int texture_index)
 {
     char    **split;
     char    *path;

     trim_line_endings(line);
     split = ft_split(line, ' ');
     if (!split || !split[1] || split[2])
     {
         free_split(split);
         return (error_handler(INVALID_TEXTURE), 0);
     }
     if (map->texture[texture_index].img)
     {
         free_split(split);
         return (error_handler(INVALID_TEXTURE), 0);
     }
     path = ft_strdup(split[1]);
     free_split(split);
     if (!path)
         return (error_handler(MALLOC_ERROR), 0);
     // 텍스처 경로는 나중에 load_textures 함수에서 처리
     return (1);
 }

 static int  validate_color_values(char **colors, int *color)
 {
     int i;

     i = 0;
     while (i < 3)
     {
         color[i] = ft_atoi(colors[i]);
         if (color[i] < 0 || color[i] > 255)
         {
             free_split(colors);
             return (error_handler(INVALID_COLOR), 0);
         }
         i++;
     }
     free_split(colors);
     return (1);
 }

 static int  parse_color(char *line, int *color)
 {
     char    **split;
     char    **colors;

     trim_line_endings(line);
     split = ft_split(line, ' ');
     if (!split || !split[1] || split[2])
     {
         free_split(split);
         return (error_handler(INVALID_COLOR), 0);
     }
     colors = ft_split(split[1], ',');
     free_split(split);
     if (!colors || ft_splitlen(colors) != 3)
     {
         free_split(colors);
         return (error_handler(INVALID_COLOR), 0);
     }
     return (validate_color_values(colors, color));
 }

 static int  parse_settings(char *line, t_map *map)
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
     return (error_handler(INVALID_TEXTURE), 0);
 }

 static int  check_settings_complete(t_map *map)
 {
     int i;

     i = 0;
     while (i < TEXTURE_COUNT)
     {
         if (!map->texture[i].img)
             return (0);
         i++;
     }
     if (map->floor_color[0] == -1 || map->ceiling_color[0] == -1)
         return (0);
     return (1);
 }

 static int  process_line(char *line, t_map *map, char ***map_lines, int *map_size)
 {
     trim_line_endings(line);
     if (ft_strlen(line) > 0)
     {
         if (!check_settings_complete(map))
         {
             if (!parse_settings(line, map))
                 return (0);
         }
         else
         {
             if (!append_map_line(map_lines, map_size, line))
                 return (0);
         }
     }
     return (1);
 }

 static int  initialize_map_lines(char ***map_lines, int *map_size)
 {
     *map_lines = NULL;
     *map_size = 0;
     return (1);
 }

 int parse_cub_file(char *file_name, t_map *map)
 {
     int     fd;
     char    *line;
     char    **map_lines;
     int     map_size;

     fd = open(file_name, O_RDONLY);
     if (fd == -1)
         return (error_handler(OPEN_ERROR), 0);
     if (!initialize_map_lines(&map_lines, &map_size))
     {
         close(fd);
         return (0);
     }
     while ((line = get_next_line(fd)) != NULL)
     {
         if (!process_line(line, map, &map_lines, &map_size))
         {
             free(line);
             get_next_line_cleanup(fd);
             close(fd);
             return (0);
         }
         free(line);
     }
     close(fd);
     if (!parse_map(map_lines, map))
     {
         free_split(map_lines);
         get_next_line_cleanup(fd);
         return (0);
     }
     free_split(map_lines);
     get_next_line_cleanup(fd);
     return (1);
 }

