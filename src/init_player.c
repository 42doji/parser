/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisong <hisong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:42:44 by hisong            #+#    #+#             */
/*   Updated: 2025/02/09 00:42:44 by hisong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_player_info(t_game *game)
{
	printf("Player Position: (%f, %f)\n", \
		game->player.pos_x, game->player.pos_y);
	printf("Player Direction: (%f, %f)\n", \
		game->player.dir_x, game->player.dir_y);
	printf("Camera Plane: (%f, %f)\n", \
		game->player.plane_x, game->player.plane_y);
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (ft_strchr("NSEW", game->map->grid[i][j]))
			{
				game->player.pos_x = j + 0.5;
				game->player.pos_y = i + 0.5;
				set_player_direction(game, game->map->grid[i][j]);
				print_player_info(game);
				return ;
			}
			j++;
		}
		i++;
	}
}
