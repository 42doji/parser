/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:12:45 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:12:47 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_STRUCT_H
# define RENDER_STRUCT_H

# define WINDOW_WIDTH 720
# define WINDOW_HEIGHT 480
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03
# define TARGET_FPS 60.0

# define TEXTURE_NORTH 0
# define TEXTURE_SOUTH 1
# define TEXTURE_EAST  2
# define TEXTURE_WEST  3
# define TEXTURE_COUNT 4

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
} t_img;

typedef struct s_ray
{
    double  camera_x;
    double  ray_dir_x;
    double  ray_dir_y;
    int     map_x;
    int     map_y;
    double  delta_dist_x;
    double  delta_dist_y;
    double  side_dist_x;
    double  side_dist_y;
    double  perp_wall_dist;
    int     step_x;
    int     step_y;
    int     hit;
    int     side;
    int     line_height;
    int     draw_start;
    int     draw_end;
} t_ray;

typedef struct s_player
{
    double  pos_x;
    double  pos_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
} t_player;

typedef struct s_keys
{
    int     w;
    int     a;
    int     s;
    int     d;
    int     left;
    int     right;
} t_keys;

typedef struct s_map t_map;

typedef struct s_game
{
    void        *mlx;
    void        *win;
    t_img       img;
    t_player    player;
    t_map       *map;
    t_keys      keys;
} t_game;

#endif
