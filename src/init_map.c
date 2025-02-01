/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:20:59 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:21:00 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_map	*create_map(void)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		error_handler(MALLOC_ERROR, NULL, NULL);
		return (NULL);
	}
	return (map);
}

static void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid && map->grid[i])
	{
		printf("%s\n", map->grid[i]);
		i++;
	}
}

static int	print_init_map(t_map *map)
{
	if (!map)
		return (0);
	printf("--------------------\n");
	printf("MAP INIT------------\n");
	printf("--------------------\n");
	printf("NO: %s\n", map->texture[TEXTURE_NORTH].path ? 
		map->texture[TEXTURE_NORTH].path : "Not Loaded");
	printf("SO: %s\n", map->texture[TEXTURE_SOUTH].path ? 
		map->texture[TEXTURE_SOUTH].path : "Not Loaded");
	printf("EA: %s\n", map->texture[TEXTURE_EAST].path ? 
		map->texture[TEXTURE_EAST].path : "Not Loaded");
	printf("WE: %s\n", map->texture[TEXTURE_WEST].path ? 
		map->texture[TEXTURE_WEST].path : "Not Loaded");
	printf("floor_color: %d, %d, %d\n", map->floor_color.r,
		map->floor_color.g, map->floor_color.b);
	printf("ceiling_color: %d, %d, %d\n", map->ceiling_color.r,
		map->ceiling_color.g, map->ceiling_color.b);
	printf("width: %d, height: %d.\n", map->width, map->height);
	print_map(map);
	printf("--------------------\n");
	printf("MAP INIT END--------\n");
	printf("--------------------\n");
	return (1);
}

t_map	*init_map(char *file_name)
{
	t_map	*map;
	int		fd;

	map = create_map();
	if (!map)
		return (NULL);
	if (!init_map_values(map))
	{
		free_map_resources(NULL, map);
		return (NULL);
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free_map_resources(NULL, map);
		error_handler(OPEN_ERROR, NULL, NULL);
		return (NULL);
	}
	if (!parse_cub_file(file_name, map))
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	if (!print_init_map(map))
	{
		free_map_resources(NULL, map);
		return (NULL);
	}
	return (map);
}
