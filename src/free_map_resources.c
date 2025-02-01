/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_resources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:20:57 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:20:57 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_textures(t_game *game, t_map *map)
{
	int	i;

	i = 0;
	while (i < TEXTURE_COUNT)
	{
		if (map->texture[i].path)
		{
			free(map->texture[i].path);
			map->texture[i].path = NULL;
		}
		if (game && game->mlx && map->texture[i].img.img)
		{
			mlx_destroy_image(game->mlx, map->texture[i].img.img);
			map->texture[i].img.img = NULL;
		}
		map->texture[i].img.addr = NULL;
		i++;
	}
}

static void	free_grid(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->height && map->grid[i])
	{
		free(map->grid[i]);
		map->grid[i] = NULL;
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	free_map_resources(t_game *game, t_map *map)
{
	if (!map)
		return ;
	free_textures(game, map);
	free_grid(map);
	free(map);
}
