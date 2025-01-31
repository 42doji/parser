#include "cub3d.h"

 static int load_single_texture(t_game *game, int texture_index)
 {
     game->map->texture[texture_index].img.img = mlx_xpm_file_to_image(
         game->mlx,
         game->map->texture[texture_index].path,
         &game->map->texture[texture_index].img.width,
         &game->map->texture[texture_index].img.height
     );
     if (!game->map->texture[texture_index].img.img)
         return (0);
     game->map->texture[texture_index].img.addr = mlx_get_data_addr(
         game->map->texture[texture_index].img.img,
         &game->map->texture[texture_index].img.bits_per_pixel,
         &game->map->texture[texture_index].img.line_length,
         &game->map->texture[texture_index].img.endian
     );
     if (!game->map->texture[texture_index].img.addr)
         return (0);
     return (1);
 }


 int load_textures(t_game *game)
 {
     int i;

     i = 0;
     while (i < TEXTURE_COUNT)
     {
         if (!game->map->texture[i].path)
         {
             i++;
             continue;
         }
         if (!load_single_texture(game, i))
         {
             error_handler(TEXTURE_ERROR);
             return (0);
         }
         i++;
     }
     return (1);
 }