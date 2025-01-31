#include "cub3d.h"
#include <sys/time.h>

#define MAX_ELAPSED_TIME (1.0 / TARGET_FPS)

static double	calculate_elapsed_time(struct timeval *last_time,
    struct timeval *current_time)
{
    double	elapsed;

    gettimeofday(current_time, NULL);
    if (last_time->tv_sec == 0 && last_time->tv_usec == 0)
    {
        *last_time = *current_time;
        return (0.0);
    }
    elapsed = (current_time->tv_sec - last_time->tv_sec) +
        (current_time->tv_usec - last_time->tv_usec) / 1000000.0;
    return (elapsed);
}

int	game_loop(t_game *game)
{
    static struct timeval	last_time = {0, 0};
    struct timeval			current_time;
    double					elapsed;

    elapsed = calculate_elapsed_time(&last_time, &current_time);
    if (elapsed >= MAX_ELAPSED_TIME)
    {
        update_game_state(game, elapsed);
        draw_frame(game);
        last_time = current_time;
    }
    return (0);
}
