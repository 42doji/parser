#include "cub3d.h"

static void	cleanup_all_fd(void)
{
	int	fd;

	for (fd = 0; fd < 4096; fd++)
		get_next_line_cleanup(fd);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	game;

	atexit(cleanup_all_fd);
	if (argc != 2)
	{
		error_handler(ARG_ERROR);
		return (EXIT_FAILURE);
	}
	if (!is_valid_extension(argv[1], ".cub"))
	{
		error_handler(FILE_NAME_ERROR);
		return (EXIT_FAILURE);
	}
	if (!is_valid_file(argv[1]))
		return (EXIT_FAILURE);
	map = init_map(argv[1]);
	if (!map || !init_game(&game, map))
	{
		free_map_resources(map);
		return (EXIT_FAILURE);
	}
	mlx_hook(game.window, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.window, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
