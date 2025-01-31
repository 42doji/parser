/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:30:00 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 20:30:00 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		error_handler(MLX_INIT_ERROR, game, game->map);
		return (0);
	}
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!game->win)
	{
		error_handler(MLX_WINDOW_ERROR, game, game->map);
		return (0);
	}
	return (1);
}

static int	init_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img.img)
	{
		error_handler(MLX_IMAGE_ERROR, game, game->map);
		return (0);
	}
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	if (!game->img.addr)
	{
		error_handler(MLX_IMAGE_ERROR, game, game->map);
		return (0);
	}
	return (1);
}

static void	init_keys(t_game *game)
{
	game->keys.w = 0;
	game->keys.a = 0;
	game->keys.s = 0;
	game->keys.d = 0;
	game->keys.left = 0;
	game->keys.right = 0;
}

int	init_game(t_game *game, t_map *map)
{
	game->map = map;
	if (!init_mlx(game))
		return (0);
	if (!init_image(game))
	{
		mlx_destroy_window(game->mlx, game->win);
		return (0);
	}
	if (!load_textures(game))
	{
		mlx_destroy_image(game->mlx, game->img.img);
		mlx_destroy_window(game->mlx, game->win);
		return (0);
	}
	init_keys(game);
	init_player(game);
	return (1);
}
