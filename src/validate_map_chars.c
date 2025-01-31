/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:00:00 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 19:00:00 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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


static int	validate_map_size(char **grid, int height, int width)
{
	if (!grid || height <= 0 || width <= 0)
	{
		error_handler(MAP_SIZE_ERROR);
		return (0);
	}
	return (1);
}

static int	validate_map_content(char **grid, int height, int width)
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
	return (1);
}

static int	check_player_count(char **grid, int height, int width)
{
	int	i;
	int	j;
	int	count;

	if (!grid)
		return (0);
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

int	validate_map_chars(char **grid, int height, int width)
{
	if (!validate_map_size(grid, height, width))
		return (0);
	if (!validate_map_content(grid, height, width))
		return (0);
	if (check_player_count(grid, height, width) != 1)
	{
		error_handler(MAP_PLAYER_ERROR);
		return (0);
	}
	return (1);
}
