/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisong <hisong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:39:48 by hisong            #+#    #+#             */
/*   Updated: 2025/02/09 00:39:48 by hisong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_game *game, t_ray *ray, int x)
{
	double	inv_dir_x;
	double	inv_dir_y;

	ray->camera_x = 2.0 * (double)x / (double)WINDOW_WIDTH - 1.0;
	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	inv_dir_x = 1.0 / ray->ray_dir_x;
	inv_dir_y = 1.0 / ray->ray_dir_y;
	ray->delta_dist_x = fabs(inv_dir_x);
	ray->delta_dist_y = fabs(inv_dir_y);
	ray->hit = 0;
}

void	calculate_step_and_side_dist(t_game *game, t_ray *ray)
{
	double	px;
	double	py;

	px = game->player.pos_x;
	py = game->player.pos_y;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (px - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - px) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (py - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - py) * ray->delta_dist_y;
	}
}

void	calculate_wall_distance(t_game *game, t_ray *ray)
{
	double	px;
	double	py;

	px = game->player.pos_x;
	py = game->player.pos_y;
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->map_x - px + (1 - ray->step_x) / 2.0)
			/ ray->ray_dir_x;
	}
	else
	{
		ray->perp_wall_dist = (ray->map_y - py + (1 - ray->step_y) / 2.0)
			/ ray->ray_dir_y;
	}
}
