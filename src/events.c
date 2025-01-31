#include "cub3d.h"

#include "cub3d.h"

 int handle_keypress(int keycode, t_game *game)
 {
     if (keycode == KEY_ESC)
         close_window(game);
     if (keycode == KEY_W)
     {
         // 앞으로 이동
         if (game->map->grid[(int)(game->player.pos_y)][(int)(game->player.pos_x + game->player.dir_x * MOVE_SPEED)] != '1')
             game->player.pos_x += game->player.dir_x * MOVE_SPEED;
         if (game->map->grid[(int)(game->player.pos_y + game->player.dir_y * MOVE_SPEED)][(int)(game->player.pos_x)] != '1')
             game->player.pos_y += game->player.dir_y * MOVE_SPEED;
     }
     if (keycode == KEY_S)
     {
         // 뒤로 이동
         if (game->map->grid[(int)(game->player.pos_y)][(int)(game->player.pos_x - game->player.dir_x * MOVE_SPEED)] != '1')
             game->player.pos_x -= game->player.dir_x * MOVE_SPEED;
         if (game->map->grid[(int)(game->player.pos_y - game->player.dir_y * MOVE_SPEED)][(int)(game->player.pos_x)] != '1')
             game->player.pos_y -= game->player.dir_y * MOVE_SPEED;
     }
     if (keycode == KEY_A)
     {
         // 왼쪽으로 회전
         double old_dir_x = game->player.dir_x;
         game->player.dir_x = game->player.dir_x * cos(ROT_SPEED) - game->player.dir_y * sin(ROT_SPEED);
         game->player.dir_y = old_dir_x * sin(ROT_SPEED) + game->player.dir_y * cos(ROT_SPEED);
         double old_plane_x = game->player.plane_x;
         game->player.plane_x = game->player.plane_x * cos(ROT_SPEED) - game->player.plane_y * sin(ROT_SPEED);
         game->player.plane_y = old_plane_x * sin(ROT_SPEED) + game->player.plane_y * cos(ROT_SPEED);
     }
     if (keycode == KEY_D)
     {
         // 오른쪽으로 회전
         double old_dir_x = game->player.dir_x;
         game->player.dir_x = game->player.dir_x * cos(-ROT_SPEED) - game->player.dir_y * sin(-ROT_SPEED);
         game->player.dir_y = old_dir_x * sin(-ROT_SPEED) + game->player.dir_y * cos(-ROT_SPEED);
         double old_plane_x = game->player.plane_x;
         game->player.plane_x = game->player.plane_x * cos(-ROT_SPEED) - game->player.plane_y * sin(-ROT_SPEED);
         game->player.plane_y = old_plane_x * sin(-ROT_SPEED) + game->player.plane_y * cos(-ROT_SPEED);
     }
     return (0);
 }

 int close_window(t_game *game)
 {
     mlx_destroy_image(game->mlx, game->img.img);
     mlx_destroy_window(game->mlx, game->win);
     free_map_resources(game->map);
     exit(EXIT_SUCCESS);
 }