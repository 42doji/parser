#include "cub3d.h"

static void	set_player_direction(t_game *game, char direction)
{
	if (direction == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (direction == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (direction == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (direction == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

static void	print_player_info(t_game *game)
{
	printf("Player Position: (%f, %f)\n", game->player.pos_x, game->player.pos_y);
	printf("Player Direction: (%f, %f)\n", game->player.dir_x, game->player.dir_y);
	printf("Camera Plane: (%f, %f)\n", game->player.plane_x, game->player.plane_y);
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
