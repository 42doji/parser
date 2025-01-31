#include "cub3d.h"

void	init_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	calculate_step_and_side_dist(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x) * 
			ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x) * 
			ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y) * 
			ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y) * 
			ray->delta_dist_y;
	}
}

void	calculate_wall_distance(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.pos_x + 
			(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.pos_y + 
			(1 - ray->step_y) / 2) / ray->ray_dir_y;
}

