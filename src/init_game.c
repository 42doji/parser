#include "cub3d.h"

static int  load_textures(t_game *game)
 {
     int width;
     int height;

     game->map->texture[NO].img = mlx_xpm_file_to_image(game->mlx, game->map->texture[NO].path, &width, &height);
     game->map->texture[SO].img = mlx_xpm_file_to_image(game->mlx, game->map->texture[SO].path, &width, &height);
     game->map->texture[EA].img = mlx_xpm_file_to_image(game->mlx, game->map->texture[EA].path, &width, &height);
     game->map->texture[WE].img = mlx_xpm_file_to_image(game->mlx, game->map->texture[WE].path, &width, &height);

     if (!game->map->texture[NO].img || !game->map->texture[SO].img ||
         !game->map->texture[EA].img || !game->map->texture[WE].img)
         return (error_handler(TEXTURE_LOADING_ERROR), 0);

     game->map->texture[NO].addr = mlx_get_data_addr(game->map->texture[NO].img,
                             &game->map->texture[NO].bits_per_pixel,
                             &game->map->texture[NO].line_length,
                             &game->map->texture[NO].endian);
     game->map->texture[SO].addr = mlx_get_data_addr(game->map->texture[SO].img,
                             &game->map->texture[SO].bits_per_pixel,
                             &game->map->texture[SO].line_length,
                             &game->map->texture[SO].endian);
     game->map->texture[EA].addr = mlx_get_data_addr(game->map->texture[EA].img,
                             &game->map->texture[EA].bits_per_pixel,
                             &game->map->texture[EA].line_length,
                             &game->map->texture[EA].endian);
     game->map->texture[WE].addr = mlx_get_data_addr(game->map->texture[WE].img,
                             &game->map->texture[WE].bits_per_pixel,
                             &game->map->texture[WE].line_length,
                             &game->map->texture[WE].endian);

     if (!game->map->texture[NO].addr || !game->map->texture[SO].addr ||
         !game->map->texture[EA].addr || !game->map->texture[WE].addr)
         return (error_handler(TEXTURE_DATA_ERROR), 0);

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
     game->win = mlx_new_window(game->mlx, WINDOW_WIDTH,
         WINDOW_HEIGHT, "cub3D");
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
         free_map_resources(game->map);
         return (0);
     }
     init_player(game);
     return (1);
 }