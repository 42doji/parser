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

void free_map_resources(t_map *map)
{
    int i;

    if (!map)
        return;
    
    i = 0;
    while (i < TEXTURE_COUNT)
    {
        if (map->texture[i])
            free(map->texture[i]);
        i++;
    }

    if (map->grid)
    {
        i = 0;
        while (i < map->height)
        {
            free(map->grid[i]);
            i++;
        }
        free(map->grid);
    }
    free(map);
}
