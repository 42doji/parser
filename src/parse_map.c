/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:21:16 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:21:17 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_map_lines(char **lines)
{
	int	count;
	int	i;

	if (!lines)
	{
		error_handler(MAP_SIZE_ERROR);
		return (0);
	}
	count = 0;
	i = 0;
	while (lines[i])
	{
		if (ft_strlen(lines[i]) > 0)
			count++;
		i++;
	}
	return (count);
}

static int	get_map_width(char **lines)
{
	int	max_width;
	int	current_width;
	int	i;

	if (!lines)
		return (0);
	max_width = 0;
	i = 0;
	while (lines[i])
	{
		current_width = ft_strlen(lines[i]);
		if (current_width > max_width)
			max_width = current_width;
		i++;
	}
	return (max_width);
}

int	init_grid_row(char **grid, int i, int width)
{
	if (!grid)
		return (0);
	grid[i] = (char *)malloc(sizeof(char) * (width + 1));
	if (!grid[i])
	{
		error_handler(MALLOC_ERROR);
		while (--i >= 0)
			free(grid[i]);
		free(grid);
		return (0);
	}
	ft_memset(grid[i], ' ', width);
	grid[i][width] = '\0';
	return (1);
}

int	parse_map(char **lines, t_map *map)
{
	if (!lines || !map)
		return (error_handler(MAP_SIZE_ERROR), 0);
	map->height = count_map_lines(lines);
	if (map->height < 3)
		return (error_handler(MAP_SIZE_ERROR), 0);
	map->width = get_map_width(lines);
	if (map->width < 3)
		return (error_handler(MAP_SIZE_ERROR), 0);
	map->grid = create_map_grid(lines, map->height, map->width);
	if (!map->grid)
		return (0);
	if (!validate_map_chars(map->grid, map->height, map->width))
		return (0);
	if (!check_walls(map->grid, map))
		return (0);
	return (1);
}
