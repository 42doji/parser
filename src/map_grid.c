/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:30:00 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 18:30:00 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**allocate_grid(int height)
{
	char	**grid;

	grid = (char **)malloc(sizeof(char *) * (height + 1));
	if (!grid)
		error_handler(MALLOC_ERROR);
	return (grid);
}

static void	fill_grid(char **grid, char **lines, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		if (!init_grid_row(grid, i, width))
			return ;
		j = 0;
		while (lines[i][j] && j < width)
		{
			grid[i][j] = lines[i][j];
			j++;
		}
		i++;
	}
	grid[height] = NULL;
}

char	**create_map_grid(char **lines, int height, int width)
{
	char	**grid;

	if (!lines || height <= 0 || width <= 0)
		return (NULL);
	grid = allocate_grid(height);
	if (!grid)
		return (NULL);
	fill_grid(grid, lines, height, width);
	return (grid);
}
