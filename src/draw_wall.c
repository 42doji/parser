/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisong <hisong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:30:00 by doji              #+#    #+#             */
/*   Updated: 2025/02/09 00:58:13 by hisong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tex_x(t_game *game, t_ray *ray, int tex_num, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * game->map->texture[tex_num].img.width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || \
		(ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = game->map->texture[tex_num].img.width - tex_x - 1;
	return (tex_x);
}

static void	draw_wall_pixels(t_game *game, t_ray *ray, \
	int x, int tex_num, int tex_x)
{
	int				y;
	unsigned int	color;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		color = get_texture_color(&game->map->texture[tex_num].img, \
			tex_x, ((y - WINDOW_HEIGHT / 2 + ray->line_height / 2) * \
			game->map->texture[tex_num].img.height) / ray->line_height);
		put_pixel(&game->img, x, y, color);
		y++;
	}
}

void	draw_wall_line(t_game *game, t_ray *ray, int x)
{
	int		tex_num;
	double	wall_x;
	int		tex_x;

	tex_num = get_texture_number(ray);
	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = get_tex_x(game, ray, tex_num, wall_x);
	draw_wall_pixels(game, ray, x, tex_num, tex_x);
}
