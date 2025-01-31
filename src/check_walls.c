/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:30:00 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 19:30:00 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall_breach(char **grid, int i, int j, t_map *map)
{
	if (!grid || !map)
		return (1);
	if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
		return (1);
	if (i > 0 && i < map->height - 1 && j > 0 && j < map->width - 1)
	{
		if (grid[i - 1][j] == ' ' || grid[i + 1][j] == ' ' ||
			grid[i][j - 1] == ' ' || grid[i][j + 1] == ' ')
			return (1);
	}
	return (0);
}

static int	validate_grid_and_map(char **grid, t_map *map)
{
	if (!grid || !map)
	{
		error_handler(MAP_WALL_ERROR);
		return (0);
	}
	return (1);
}

static int	validate_wall_integrity(char **grid, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (grid[i][j] != '1' && grid[i][j] != ' ')
			{
				if (is_wall_breach(grid, i, j, map))
				{
					error_handler(MAP_WALL_ERROR);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_walls(char **grid, t_map *map)
{
	if (!validate_grid_and_map(grid, map))
		return (0);
	return (validate_wall_integrity(grid, map));
}
