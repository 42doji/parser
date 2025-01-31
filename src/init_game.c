#include "cub3d.h"

static int	load_single_texture(t_game *game, int texture_index)
{
    game->map->texture[texture_index].img.img = mlx_xpm_file_to_image(
        game->mlx,
        game->map->texture[texture_index].path,
        &game->map->texture[texture_index].img.width,
        &game->map->texture[texture_index].img.height
    );
    if (!game->map->texture[texture_index].img.img)
    {
        #ifdef DEBUG
        printf("Failed to load texture %d\n", texture_index);
        #endif
        return (0);
    }
    
    game->map->texture[texture_index].img.addr = mlx_get_data_addr(
        game->map->texture[texture_index].img.img,
        &game->map->texture[texture_index].img.bits_per_pixel,
        &game->map->texture[texture_index].img.line_length,
        &game->map->texture[texture_index].img.endian
    );
    if (!game->map->texture[texture_index].img.addr)
    {
        #ifdef DEBUG
        printf("Failed to get texture address %d\n", texture_index);
        #endif
        return (0);
    }
    return (1);
}

int	load_textures(t_game *game)
{
    int i;

    #ifdef DEBUG
    printf("Loading textures...\n");
    #endif
    
    i = 0;
    while (i < TEXTURE_COUNT)
    {
        if (!load_single_texture(game, i))
        {
            error_handler(TEXTURE_ERROR);
            return (0);
        }
        i++;
    }

    #ifdef DEBUG
    printf("Texture loading complete.\n");
    #endif
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
    game->keys.w = 0;
    game->keys.a = 0;
    game->keys.s = 0;
    game->keys.d = 0;
    game->keys.left = 0;
    game->keys.right = 0;
    #ifdef DEBUG
    printf("Keys initialized - W: %d, A: %d, S: %d, D: %d, LEFT: %d, RIGHT: %d\n",
           game->keys.w, game->keys.a, game->keys.s, game->keys.d,
           game->keys.left, game->keys.right);
    #endif
    init_player(game);
    return (1);
}
