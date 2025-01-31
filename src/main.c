#include "../include/cub3d.h"

int main(int argc, char **argv)
{
    t_map *map;
    t_game game;

    ft_bzero(&game, sizeof(t_game));
    if (argc != 2)
    {
        error_handler(INVALID_ARGUMENTS);
        return (EXIT_FAILURE);
    }
    if (!is_valid_extension(argv[1], ".cub"))
    {
        error_handler(INVALID_FILE_EXTENSION);
        return (EXIT_FAILURE);
    }
    if (!is_valid_file(argv[1])) 
        return (EXIT_FAILURE);
    map = init_map(argv[1]);
    if (!map)
    {
        error_handler(MAP_INITIALIZATION_ERROR);
        return (EXIT_FAILURE);
    }
    if (!init_game(&game, map))
    {
        free_map_resources(&game, map);
        error_handler(GAME_INITIALIZATION_ERROR);
        return (EXIT_FAILURE);
    }
    mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
    mlx_hook(game.win, 3, 1L << 1, handle_keyrelease, &game);
    mlx_hook(game.win, 17, 0, close_window, &game);
    mlx_loop_hook(game.mlx, game_loop, &game);
    mlx_loop(game.mlx);
    return (0);
}
