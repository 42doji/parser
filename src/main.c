/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:00:00 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 18:00:00 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	validate_arguments(int argc, char *filename)
{
	if (argc != 2)
	{
		error_handler(INVALID_ARGUMENTS, NULL, NULL);
		return (0);
	}
	if (!is_valid_extension(filename, ".cub"))
	{
		error_handler(INVALID_FILE_EXTENSION, NULL, NULL);
		return (0);
	}
	if (!is_valid_file(filename))
		return (0);
	return (1);
}

static t_map	*setup_map(char *filename)
{
	t_map	*map;

	map = init_map(filename);
	if (!map)
		error_handler(MAP_INITIALIZATION_ERROR, NULL, NULL);
	return (map);
}

static int	setup_game(t_game *game, t_map *map)
{
	if (!init_game(game, map))
	{
		free_map_resources(game, map);
		error_handler(GAME_INITIALIZATION_ERROR, game, map);
		return (0);
	}
	return (1);
}

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 3, 1L << 1, handle_keyrelease, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, game_loop, game);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (!validate_arguments(argc, argv[1]))
		return (EXIT_FAILURE);
	map = setup_map(argv[1]);
	if (!map)
		return (EXIT_FAILURE);
	if (!setup_game(&game, map))
		return (EXIT_FAILURE);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
