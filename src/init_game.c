#include "cub3d.h"

int load_textures(t_game *game)
{
    printf("Loading textures...\n");
    printf("North texture path: %s\n", game->map->texture[TEXTURE_NORTH].path);
    printf("South texture path: %s\n", game->map->texture[TEXTURE_SOUTH].path);
    printf("East texture path: %s\n", game->map->texture[TEXTURE_EAST].path);
    printf("West texture path: %s\n", game->map->texture[TEXTURE_WEST].path);

    game->map->texture[TEXTURE_NORTH].img.img = mlx_xpm_file_to_image(game->mlx, 
        game->map->texture[TEXTURE_NORTH].path, 
        &game->map->texture[TEXTURE_NORTH].img.width, 
        &game->map->texture[TEXTURE_NORTH].img.height);
    game->map->texture[TEXTURE_SOUTH].img.img = mlx_xpm_file_to_image(game->mlx, 
        game->map->texture[TEXTURE_SOUTH].path, 
        &game->map->texture[TEXTURE_SOUTH].img.width, 
        &game->map->texture[TEXTURE_SOUTH].img.height);
    game->map->texture[TEXTURE_EAST].img.img = mlx_xpm_file_to_image(game->mlx, 
        game->map->texture[TEXTURE_EAST].path, 
        &game->map->texture[TEXTURE_EAST].img.width, 
        &game->map->texture[TEXTURE_EAST].img.height);
    game->map->texture[TEXTURE_WEST].img.img = mlx_xpm_file_to_image(game->mlx, 
        game->map->texture[TEXTURE_WEST].path, 
        &game->map->texture[TEXTURE_WEST].img.width, 
        &game->map->texture[TEXTURE_WEST].img.height);

    if (!game->map->texture[TEXTURE_NORTH].img.img)
        printf("Failed to load North texture\n");
    if (!game->map->texture[TEXTURE_SOUTH].img.img)
        printf("Failed to load South texture\n");
    if (!game->map->texture[TEXTURE_EAST].img.img)
        printf("Failed to load East texture\n");
    if (!game->map->texture[TEXTURE_WEST].img.img)
        printf("Failed to load West texture\n");

    if (!game->map->texture[TEXTURE_NORTH].img.img || !game->map->texture[TEXTURE_SOUTH].img.img ||
        !game->map->texture[TEXTURE_EAST].img.img || !game->map->texture[TEXTURE_WEST].img.img)
    {
        error_handler(TEXTURE_ERROR);
        return (0);
    }

    game->map->texture[TEXTURE_NORTH].img.addr = mlx_get_data_addr(
        game->map->texture[TEXTURE_NORTH].img.img,
        &game->map->texture[TEXTURE_NORTH].img.bits_per_pixel,
        &game->map->texture[TEXTURE_NORTH].img.line_length,
        &game->map->texture[TEXTURE_NORTH].img.endian);
    game->map->texture[TEXTURE_SOUTH].img.addr = mlx_get_data_addr(
        game->map->texture[TEXTURE_SOUTH].img.img,
        &game->map->texture[TEXTURE_SOUTH].img.bits_per_pixel,
        &game->map->texture[TEXTURE_SOUTH].img.line_length,
        &game->map->texture[TEXTURE_SOUTH].img.endian);
    game->map->texture[TEXTURE_EAST].img.addr = mlx_get_data_addr(
        game->map->texture[TEXTURE_EAST].img.img,
        &game->map->texture[TEXTURE_EAST].img.bits_per_pixel,
        &game->map->texture[TEXTURE_EAST].img.line_length,
        &game->map->texture[TEXTURE_EAST].img.endian);
    game->map->texture[TEXTURE_WEST].img.addr = mlx_get_data_addr(
        game->map->texture[TEXTURE_WEST].img.img,
        &game->map->texture[TEXTURE_WEST].img.bits_per_pixel,
        &game->map->texture[TEXTURE_WEST].img.line_length,
        &game->map->texture[TEXTURE_WEST].img.endian);

    if (!game->map->texture[TEXTURE_NORTH].img.addr)
        printf("Failed to get North texture address\n");
    if (!game->map->texture[TEXTURE_SOUTH].img.addr)
        printf("Failed to get South texture address\n");
    if (!game->map->texture[TEXTURE_EAST].img.addr)
        printf("Failed to get East texture address\n");
    if (!game->map->texture[TEXTURE_WEST].img.addr)
        printf("Failed to get West texture address\n");

    if (!game->map->texture[TEXTURE_NORTH].img.addr || !game->map->texture[TEXTURE_SOUTH].img.addr ||
        !game->map->texture[TEXTURE_EAST].img.addr || !game->map->texture[TEXTURE_WEST].img.addr)
    {
        error_handler(TEXTURE_ERROR);
        return (0);
    }

    printf("Texture loading complete. Dimensions:\n");
    printf("North: %dx%d\n", game->map->texture[TEXTURE_NORTH].img.width, 
        game->map->texture[TEXTURE_NORTH].img.height);
    printf("South: %dx%d\n", game->map->texture[TEXTURE_SOUTH].img.width, 
        game->map->texture[TEXTURE_SOUTH].img.height);
    printf("East: %dx%d\n", game->map->texture[TEXTURE_EAST].img.width, 
        game->map->texture[TEXTURE_EAST].img.height);
    printf("West: %dx%d\n", game->map->texture[TEXTURE_WEST].img.width, 
        game->map->texture[TEXTURE_WEST].img.height);

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
        return (0);
    }
    init_player(game);
    return (1);
}
