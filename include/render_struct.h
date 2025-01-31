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
#define RENDER_STRUCT_H

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define MOVE_SPEED 0.05
#define ROT_SPEED 0.03

typedef struct s_img
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    int width;
    int height;
} t_img;

typedef struct s_vector
{
    double x;
    double y;
} t_vector;

typedef struct s_player
{
    t_vector position;
    t_vector direction;
    t_vector plane;
} t_player;

typedef struct s_ray
{
    double camera_x;
    t_vector ray_dir;
    t_vector map;
    t_vector side_dist;
    t_vector delta_dist;
    double perp_wall_dist;
    t_vector step;
    int hit;
    int side;
    int line_height;
    int draw_start;
    int draw_end;
} t_ray;

typedef struct s_map t_map;

typedef struct s_game
{
    void *mlx;
    void *win;
    t_img img;
    t_player player;
    t_map map;
} t_game;

#endif
