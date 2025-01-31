/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:30:00 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 16:30:00 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_textures(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < TEXTURE_COUNT)
	{
		if (map->texture[i].path)
		{
			free(map->texture[i].path);
			map->texture[i].path = NULL;
		}
		i++;
	}
}

static void	free_grid(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i])
		{
			free(map->grid[i]);
			map->grid[i] = NULL;
		}
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	cleanup_map(t_map *map)
{
	if (!map)
		return ;
	free_textures(map);
	free_grid(map);
	free(map);
}
