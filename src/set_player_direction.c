/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_direction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisong <hisong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:30:00 by doji              #+#    #+#             */
/*   Updated: 2025/02/10 16:09:32 by hisong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_vector(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (direction == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (direction == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (direction == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
}

static void	set_plane_x(t_player *player, char direction)
{
	if (direction == 'N')
		player->plane_x = 0.66;
	else if (direction == 'S')
		player->plane_x = -0.66;
	else
		player->plane_x = 0;
}

static void	set_plane_y(t_player *player, char direction)
{
	if (direction == 'E')
		player->plane_y = 0.66;
	else if (direction == 'W')
		player->plane_y = -0.66;
	else
		player->plane_y = 0;
}

static void	set_camera_plane(t_player *player, char direction)
{
	set_plane_x(player, direction);
	set_plane_y(player, direction);
}

void	set_player_direction(t_game *game, char direction)
{
	set_player_vector(&game->player, direction);
	set_camera_plane(&game->player, direction);
}
