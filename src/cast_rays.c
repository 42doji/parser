#include "cub3d.h"

static void	init_ray(t_game *game, t_ray *ray, int x)
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

static void	calculate_step_and_side_dist(t_game *game, t_ray *ray)
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

static void	perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
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

		// Check map boundaries
		if (ray->map_x < 0 || ray->map_x >= game->map->width ||
			ray->map_y < 0 || ray->map_y >= game->map->height)
		{
			ray->hit = 1;
			return;
		}

		if (game->map->grid[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

static void	calculate_wall_distance(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.pos_x + 
			(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.pos_y + 
			(1 - ray->step_y) / 2) / ray->ray_dir_y;
}

static int	get_texture_number(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (TEXTURE_WEST);
		return (TEXTURE_EAST);
	}
	if (ray->ray_dir_y > 0)
		return (TEXTURE_SOUTH);
	return (TEXTURE_NORTH);
}

static int	get_texture_color(t_img *texture, int x, int y)
{
	char	*pixel;

	pixel = texture->addr + (y * texture->line_length + 
		x * (texture->bits_per_pixel / 8));
	return (*(unsigned int*)pixel);
}

static void	draw_wall_line(t_game *game, t_ray *ray, int x)
{
	int				tex_num;
	double			wall_x;
	int				tex_x;
	int				y;
	unsigned int	color;

	tex_num = get_texture_number(ray);
	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * game->map->texture[tex_num].img.width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || 
		(ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = game->map->texture[tex_num].img.width - tex_x - 1;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		color = get_texture_color(&game->map->texture[tex_num].img, 
			tex_x, ((y - WINDOW_HEIGHT / 2 + ray->line_height / 2) * 
			game->map->texture[tex_num].img.height) / ray->line_height);
		put_pixel(game, x, y, color);
		y++;
	}
}

void	cast_rays(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		init_ray(game, &ray, x);
		calculate_step_and_side_dist(game, &ray);
		perform_dda(game, &ray);
		calculate_wall_distance(game, &ray);

		ray.line_height = (int)(WINDOW_HEIGHT / ray.perp_wall_dist);
		ray.draw_start = -ray.line_height / 2 + WINDOW_HEIGHT / 2;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = ray.line_height / 2 + WINDOW_HEIGHT / 2;
		if (ray.draw_end >= WINDOW_HEIGHT)
			ray.draw_end = WINDOW_HEIGHT - 1;

		draw_wall_line(game, &ray, x);
		x++;
	}
}
