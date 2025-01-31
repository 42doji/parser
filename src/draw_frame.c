#include "cub3d.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.line_length + 
		x * (game->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_floor_ceiling(t_game *game)
{
	int	x;
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = (game->map->ceiling_color.r << 16) |
	                (game->map->ceiling_color.g << 8) |
	                game->map->ceiling_color.b;
	floor_color = (game->map->floor_color.r << 16) |
	              (game->map->floor_color.g << 8) |
	              game->map->floor_color.b;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (y < WINDOW_HEIGHT / 2)
				put_pixel(game, x, y, ceiling_color);
			else
				put_pixel(game, x, y, floor_color);
			x++;
		}
		y++;
	}
}

void	draw_frame(t_game *game)
{
	draw_floor_ceiling(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
