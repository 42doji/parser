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

static void print_error_message(t_error error)
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
    };
    ft_putstr_fd("Error\n", 2);
    if (error >= 0 && error < (int)(sizeof(error_msg) / sizeof(error_msg[0])))
        ft_putendl_fd((char *)error_msg[error], 2);
    else
        ft_putendl_fd("Error: Unknown error", 2);
}

static void cleanup_resources(t_game *game, t_map *map)
{
    if (game)
        cleanup_game(game);
    if (map)
        cleanup_map(map);
    get_next_line_cleanup(-1);
}

void error_handler(t_error error, t_game *game, t_map *map)
{
    print_error_message(error);
    cleanup_resources(game, map);
    exit(EXIT_FAILURE);
}
