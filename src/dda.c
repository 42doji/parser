/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisong <hisong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:00:00 by doji              #+#    #+#             */
/*   Updated: 2025/02/09 00:56:16 by hisong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_ray(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

static int	is_out_of_bounds(t_game *game, t_ray *ray)
{
	if (ray->map_x < 0 || ray->map_x >= game->map->width || \
		ray->map_y < 0 || ray->map_y >= game->map->height)
	{
		return (1);
	}
	return (0);
}

static int	check_collision(t_game *game, t_ray *ray)
{
	if (game->map->grid[ray->map_y][ray->map_x] == '1')
		return (1);
	return (0);
}

void	perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		move_ray(ray);
		if (is_out_of_bounds(game, ray))
		{
			ray->hit = 1;
			return ;
		}
		if (check_collision(game, ray))
			ray->hit = 1;
	}
}
