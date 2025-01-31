#include "cub3d.h"

int	init_game(t_game *game, t_map *map)
{
	game->map = map;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		error_handler(MLX_INIT_ERROR);
		return (0);
	}
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, 
		WINDOW_HEIGHT, "cub3D");
	if (!game->win)
	{
		error_handler(MLX_WINDOW_ERROR);
		return (0);
	}
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img.img)
	{
		error_handler(MLX_IMAGE_ERROR);
		return (0);
	}
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
		&game->img.line_length, &game->img.endian);
	if (!game->img.addr)
	{
		error_handler(MLX_DATA_ADDR_ERROR);
		return (0);
	}
	init_player(game);
	return (1);
}
