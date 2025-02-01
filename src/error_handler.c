/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:20:54 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:20:55 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    error_handler(t_error error, t_game *game, t_map *map)
{
    const char *error_msg[] = {
        "Error: No error",
        "Error: Memory allocation failed",
        "Error: Failed to open file",
        "Error: Failed to read file", 
        "Error: Invalid arguments",
        "Error: Invalid resolution",
        "Error: Invalid texture",
        "Error: Invalid color",
        "Error: Invalid map",
        "Error: Invalid file name",
        "Error: Invalid map walls",
        "Error: Invalid number of players",
        "Error: Invalid map characters",
        "Error: Map size is too small",
        "Error: MLX initialization failed",
        "Error: MLX window creation failed",
        "Error: MLX image creation failed",
        "Error: MLX data address retrieval failed",
        "Error: Invalid arguments",
        "Error: Invalid file extension",
        "Error: Map initialization failed",
        "Error: Game initialization failed",
        "Error: Duplicate key detected"
    };

    if (error >= 0 && error < (int)(sizeof(error_msg) / sizeof(error_msg[0])))
    {
        ft_putstr_fd("Error\n", 2);
        ft_putendl_fd((char *)error_msg[error], 2);
    }
    else
        ft_putendl_fd("Error: Unknown error", 2);

    if (game && game->mlx)
    {
        if (game->img.img)
            mlx_destroy_image(game->mlx, game->img.img);
        if (game->win)
            mlx_destroy_window(game->mlx, game->win);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    if (map)
        cleanup_map(map);
    if (game)
        cleanup_game(game);
    get_next_line_cleanup(-1);
    exit(EXIT_FAILURE);
}
