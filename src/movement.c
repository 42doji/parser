/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisong <hisong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:46:20 by hisong            #+#    #+#             */
/*   Updated: 2025/02/09 00:46:26 by hisong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	move(t_game *game, double move_x, double move_y,
		double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + move_x * speed;
	new_y = game->player.pos_y + move_y * speed;
	if (game->map->grid[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map->grid[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	move_forward(t_game *game, double speed)
{
	move(game, game->player.dir_x, game->player.dir_y, speed);
}

void	move_backward(t_game *game, double speed)
{
	move(game, -game->player.dir_x, -game->player.dir_y, speed);
}

void	move_left(t_game *game, double speed)
{
	move(game, -game->player.dir_y, game->player.dir_x, speed);
}

void	move_right(t_game *game, double speed)
{
	move(game, game->player.dir_y, -game->player.dir_x, speed);
}
