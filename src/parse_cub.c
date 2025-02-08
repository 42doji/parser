/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisong <hisong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:47:59 by hisong            #+#    #+#             */
/*   Updated: 2025/02/09 00:47:59 by hisong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	open_cub_file(char *file_name, t_map *map)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_handler(OPEN_ERROR, NULL, map);
	return (fd);
}

static int	initialize_map_lines(char ***map_lines, int *map_size)
{
	*map_lines = NULL;
	*map_size = 0;
	return (1);
}

static int	read_cub_file(int fd, t_map *map, char ***map_lines, int *map_size)
{
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
	{
		if (!process_line(line, map, map_lines, map_size))
		{
			free(line);
			free_map_resources(NULL, map);
			free_split(*map_lines);
			*map_lines = NULL;
			get_next_line_cleanup(fd);
			error_handler(MAP_SIZE_ERROR, NULL, map);
			return (0);
		}
		free(line);
	}
	get_next_line_cleanup(fd);
	if (*map_lines == NULL)
	{
		error_handler(MAP_SIZE_ERROR, NULL, map);
		return (0);
	}
	return (1);
}

static int	finalize_parsing(int fd, char ***map_lines, t_map *map)
{
	if (!parse_map(*map_lines, map))
	{
		free_split(*map_lines);
		*map_lines = NULL;
		free_map_resources(NULL, map);
		get_next_line_cleanup(fd);
		error_handler(MAP_ERROR, NULL, map);
	}
	free_split(*map_lines);
	close(fd);
	return (1);
}

int	parse_cub_file(char *file_name, t_map *map)
{
	int		fd;
	char	**map_lines;
	int		map_size;

	fd = open_cub_file(file_name, map);
	if (fd == -1)
		return (0);
	if (!initialize_map_lines(&map_lines, &map_size))
	{
		close(fd);
		return (0);
	}
	if (!read_cub_file(fd, map, &map_lines, &map_size))
	{
		close(fd);
		return (0);
	}
	return (finalize_parsing(fd, &map_lines, map));
}
