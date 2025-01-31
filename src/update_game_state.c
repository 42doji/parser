/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:21:20 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:21:21 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void	rotate_player(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed) - 
		game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed) + 
		game->player.dir_y * cos(rot_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed) - 
		game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed) + 
		game->player.plane_y * cos(rot_speed);
}

void	update_game_state(t_game *game, double elapsed)
{
	double	move_speed;
	double	rot_speed;

	move_speed = MOVE_SPEED * elapsed * 15;
	rot_speed = ROT_SPEED * elapsed * 15;
	if (game->keys.w)
		move_forward(game, move_speed);
	if (game->keys.s)
		move_backward(game, move_speed);
	if (game->keys.a)
		move_left(game, -move_speed);
	if (game->keys.d)
		move_right(game, -move_speed);
	if (game->keys.left)
		rotate_player(game, -rot_speed);
	if (game->keys.right)
		rotate_player(game, rot_speed);
}
