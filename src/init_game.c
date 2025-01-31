#include "cub3d.h"

int load_textures(t_game *game)
{
    game->map->texture[NO].img.img = mlx_xpm_file_to_image(game->mlx, 
        game->map->texture[NO].path, 
        &game->map->texture[NO].img.width, 
        &game->map->texture[NO].img.height);
    game->map->texture[SO].img.img = mlx_xpm_file_to_image(game->mlx, 
        game->map->texture[SO].path, 
        &game->map->texture[SO].img.width, 
        &game->map->texture[SO].img.height);
    game->map->texture[EA].img.img = mlx_xpm_file_to_image(game->mlx, 
        game->map->texture[EA].path, 
        &game->map->texture[EA].img.width, 
        &game->map->texture[EA].img.height);
    game->map->texture[WE].img.img = mlx_xpm_file_to_image(game->mlx, 
        game->map->texture[WE].path, 
        &game->map->texture[WE].img.width, 
        &game->map->texture[WE].img.height);

    if (!game->map->texture[NO].img.img || !game->map->texture[SO].img.img ||
        !game->map->texture[EA].img.img || !game->map->texture[WE].img.img)
    {
        error_handler(TEXTURE_ERROR);
        return (0);
    }

    game->map->texture[NO].img.addr = mlx_get_data_addr(
        game->map->texture[NO].img.img,
        &game->map->texture[NO].img.bits_per_pixel,
        &game->map->texture[NO].img.line_length,
        &game->map->texture[NO].img.endian);
    game->map->texture[SO].img.addr = mlx_get_data_addr(
        game->map->texture[SO].img.img,
        &game->map->texture[SO].img.bits_per_pixel,
        &game->map->texture[SO].img.line_length,
        &game->map->texture[SO].img.endian);
    game->map->texture[EA].img.addr = mlx_get_data_addr(
        game->map->texture[EA].img.img,
        &game->map->texture[EA].img.bits_per_pixel,
        &game->map->texture[EA].img.line_length,
        &game->map->texture[EA].img.endian);
    game->map->texture[WE].img.addr = mlx_get_data_addr(
        game->map->texture[WE].img.img,
        &game->map->texture[WE].img.bits_per_pixel,
        &game->map->texture[WE].img.line_length,
        &game->map->texture[WE].img.endian);

    if (!game->map->texture[NO].img.addr || !game->map->texture[SO].img.addr ||
        !game->map->texture[EA].img.addr || !game->map->texture[WE].img.addr)
    {
        error_handler(TEXTURE_ERROR);
        return (0);
    }

    return (1);
}

int init_game(t_game *game, t_map *map)
{
    game->map = map;
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        error_handler(MLX_INIT_ERROR);
        return (0);
    }
    game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
    if (!game->win)
    {
        error_handler(MLX_WINDOW_ERROR);
        return (0);
    }
    game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!game->img.img)
    {
        error_handler(MLX_IMAGE_ERROR);
        return (0);
    }
    game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
        &game->img.line_length, &game->img.endian);
    if (!game->img.addr)
    {
        error_handler(MLX_DATA_ADDR_ERROR);
        return (0);
    }
    if (!load_textures(game))
    {
        mlx_destroy_image(game->mlx, game->img.img);
        mlx_destroy_window(game->mlx, game->win);
        free_map_resources(game, game->map);
        return (0);
    }
    init_player(game);
    return (1);
}
