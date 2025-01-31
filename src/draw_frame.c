#include "cub3d.h"

 void	put_pixel(t_img *img, int x, int y, int color)
 {
     unsigned int *dst;

     dst = (unsigned int *)(img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)));
     *dst = color;
 }

 void draw_floor_ceiling(t_game *game)
 {
     int x;
     int y;
     int ceiling_color;
     int floor_color;
     char *dst;

     ceiling_color = (game->map->ceiling_color.r << 16) |
                     (game->map->ceiling_color.g << 8) |
                     game->map->ceiling_color.b;
     floor_color = (game->map->floor_color.r << 16) |
                   (game->map->floor_color.g << 8) |
                   game->map->floor_color.b;
     y = 0;
     while (y < WINDOW_HEIGHT)
     {
         if (y < WINDOW_HEIGHT / 2)
             dst = game->img.addr + y * game->img.line_length;
         else
             dst = game->img.addr + y * game->img.line_length;
         x = 0;
         while (x < WINDOW_WIDTH)
         {
             if (y < WINDOW_HEIGHT / 2)
                 *(unsigned int *)(dst + x * (game->img.bits_per_pixel / 8)) = ceiling_color;
             else
                 *(unsigned int *)(dst + x * (game->img.bits_per_pixel / 8)) = floor_color;
             x++;
         }
         y++;
     }
 }

void	draw_frame(t_game *game)
{
	draw_floor_ceiling(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
