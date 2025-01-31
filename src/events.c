#include "cub3d.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->win);
	free_map_resources(game->map);
	exit(0);
	return (0);
}
