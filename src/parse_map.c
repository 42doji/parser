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

static int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || 
		c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

static void	print_map_error(char c, int i, int j)
{
	ft_putstr_fd("Invalid character '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("' at line ", 2);
	ft_putnbr_fd(i + 1, 2);
	ft_putstr_fd(", column ", 2);
	ft_putnbr_fd(j + 1, 2);
	ft_putstr_fd("\n", 2);
}

static int	check_player_count(char **grid, int height, int width)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (grid[i][j] == 'N' || grid[i][j] == 'S' ||
				grid[i][j] == 'E' || grid[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static int	validate_map_chars(char **grid, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (!is_valid_map_char(grid[i][j]))
			{
				print_map_error(grid[i][j], i, j);
				error_handler(MAP_CHAR_ERROR);
				return (0);
			}
			j++;
		}
		i++;
	}
	if (check_player_count(grid, height, width) != 1)
	{
		error_handler(MAP_PLAYER_ERROR);
		return (0);
	}
	return (1);
}

static int	is_wall_breach(char **grid, int i, int j, t_map *map)
{
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

static int	check_walls(char **grid, t_map *map)
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

static int	count_map_lines(char **lines)
{
	int	count;
	int	i;

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

static int	init_grid_row(char **grid, int i, int width)
{
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

static char	**create_map_grid(char **lines, int height, int width)
{
	char	**grid;
	int		i;
	int		j;

	grid = (char **)malloc(sizeof(char *) * (height + 1));
	if (!grid)
	{
		error_handler(MALLOC_ERROR);
		return (NULL);
	}
	i = 0;
	while (i < height)
	{
		if (!init_grid_row(grid, i, width))
			return (NULL);
		j = 0;
		while (lines[i][j] && j < width)
		{
			grid[i][j] = lines[i][j];
			j++;
		}
		i++;
	}
	grid[height] = NULL;
	return (grid);
}

int	parse_map(char **lines, t_map *map)
{
	map->height = count_map_lines(lines);
	if (map->height < 3)
	{
		error_handler(MAP_SIZE_ERROR);
		return (0);
	}
	map->width = get_map_width(lines);
	if (map->width < 3)
	{
		error_handler(MAP_SIZE_ERROR);
		return (0);
	}
	map->grid = create_map_grid(lines, map->height, map->width);
	if (!map->grid)
		return (0);
	if (!validate_map_chars(map->grid, map->height, map->width))
		return (0);
	if (!check_walls(map->grid, map))
		return (0);
	return (1);
}
