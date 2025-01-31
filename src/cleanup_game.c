/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:20:54 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:20:55 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    cleanup_game(t_game *game)
{
    if (!game)
        return;
    
    if (game->mlx_ptr)
    {
        if (game->win_ptr)
            mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        if (game->img.img_ptr)
            mlx_destroy_image(game->mlx_ptr, game->img.img_ptr);
        // Free MLX itself if needed
    }
}
