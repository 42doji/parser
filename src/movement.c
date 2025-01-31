#include "cub3d.h"

void	move_forward(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * speed;
	new_y = game->player.pos_y + game->player.dir_y * speed;
	if (game->map->grid[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map->grid[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	move_backward(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * speed;
	new_y = game->player.pos_y - game->player.dir_y * speed;
	if (game->map->grid[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map->grid[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}
void	move_left(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_y * speed;
	new_y = game->player.pos_y + game->player.dir_x * speed;
	if (game->map->grid[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map->grid[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	move_right(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * speed;
	new_y = game->player.pos_y - game->player.dir_x * speed;
	if (game->map->grid[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map->grid[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}