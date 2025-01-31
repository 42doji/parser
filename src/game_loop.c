#include "cub3d.h"
#include <sys/time.h>

static void	update_player_movement(t_game *game, double elapsed)
{
	if (game->keys.w)
	{
		if (game->map->grid[(int)(game->player.pos_y)]
			[(int)(game->player.pos_x + game->player.dir_x * MOVE_SPEED)] != '1')
			game->player.pos_x += game->player.dir_x * MOVE_SPEED * elapsed * 60.0;
		if (game->map->grid[(int)(game->player.pos_y + game->player.dir_y
				* MOVE_SPEED)][(int)(game->player.pos_x)] != '1')
			game->player.pos_y += game->player.dir_y * MOVE_SPEED * elapsed * 60.0;
	}
	if (game->keys.s)
	{
		if (game->map->grid[(int)(game->player.pos_y)]
			[(int)(game->player.pos_x - game->player.dir_x * MOVE_SPEED)] != '1')
			game->player.pos_x -= game->player.dir_x * MOVE_SPEED * elapsed * 60.0;
		if (game->map->grid[(int)(game->player.pos_y - game->player.dir_y
				* MOVE_SPEED)][(int)(game->player.pos_x)] != '1')
			game->player.pos_y -= game->player.dir_y * MOVE_SPEED * elapsed * 60.0;
	}
	if (game->keys.a)
	{
		double old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(ROT_SPEED * elapsed * 60.0)
			- game->player.dir_y * sin(ROT_SPEED * elapsed * 60.0);
		game->player.dir_y = old_dir_x * sin(ROT_SPEED * elapsed * 60.0)
			+ game->player.dir_y * cos(ROT_SPEED * elapsed * 60.0);
		double old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(ROT_SPEED * elapsed * 60.0)
			- game->player.plane_y * sin(ROT_SPEED * elapsed * 60.0);
		game->player.plane_y = old_plane_x * sin(ROT_SPEED * elapsed * 60.0)
			+ game->player.plane_y * cos(ROT_SPEED * elapsed * 60.0);
	}
	if (game->keys.d)
	{
		double old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-ROT_SPEED * elapsed * 60.0)
			- game->player.dir_y * sin(-ROT_SPEED * elapsed * 60.0);
		game->player.dir_y = old_dir_x * sin(-ROT_SPEED * elapsed * 60.0)
			+ game->player.dir_y * cos(-ROT_SPEED * elapsed * 60.0);
		double old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(-ROT_SPEED * elapsed * 60.0)
			- game->player.plane_y * sin(-ROT_SPEED * elapsed * 60.0);
		game->player.plane_y = old_plane_x * sin(-ROT_SPEED * elapsed * 60.0)
			+ game->player.plane_y * cos(-ROT_SPEED * elapsed * 60.0);
	}
}

static void	update_game_state(t_game *game, double elapsed)
{
	update_player_movement(game, elapsed);
}

int	game_loop(t_game *game)
{
	static struct timeval	last_time = {0, 0};
	struct timeval			current_time;
	double					elapsed;

	gettimeofday(&current_time, NULL);
	if (last_time.tv_sec == 0 && last_time.tv_usec == 0)
		last_time = current_time;

	elapsed = (current_time.tv_sec - last_time.tv_sec) +
		(current_time.tv_usec - last_time.tv_usec) / 1000000.0;

	if (elapsed >= 1.0 / TARGET_FPS)
	{
		update_game_state(game, elapsed);
		if (!draw_frame(game))
		{
			error_handler(DRAW_FRAME_ERROR);
			close_window(game);
			return (1);
		}
		last_time = current_time;
	}
	return (0);
}
