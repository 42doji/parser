#include "cub3d.h"

int	handle_keypress(int keycode, t_game *game)
{
    #ifdef DEBUG
    printf("Key Pressed: %d\n", keycode);
    #endif

    if (keycode == KEY_ESC)
        close_window(game);
    else if (keycode == KEY_W)
        game->keys.w = 1;
    else if (keycode == KEY_A)
        game->keys.a = 1;
    else if (keycode == KEY_S)
        game->keys.s = 1;
    else if (keycode == KEY_D)
        game->keys.d = 1;
    else if (keycode == KEY_LEFT)
        game->keys.left = 1;
    else if (keycode == KEY_RIGHT)
        game->keys.right = 1;
    return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
    #ifdef DEBUG
    printf("Key Released: %d\n", keycode);
    #endif

    if (keycode == KEY_W)
        game->keys.w = 0;
    else if (keycode == KEY_A)
        game->keys.a = 0;
    else if (keycode == KEY_S)
        game->keys.s = 0;
    else if (keycode == KEY_D)
        game->keys.d = 0;
    else if (keycode == KEY_LEFT)
        game->keys.left = 0;
    else if (keycode == KEY_RIGHT)
        game->keys.right = 0;
    return (0);
}

int	close_window(t_game *game)
{
    mlx_destroy_image(game->mlx, game->img.img);
    mlx_destroy_window(game->mlx, game->win);
    free_map_resources(game, game->map);
    exit(EXIT_SUCCESS);
}
