/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:12:45 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:12:47 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_STRUCT_H
# define MAP_STRUCT_H

# include "render_struct.h"

typedef struct s_color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} t_color;

typedef struct s_texture
{
    char    *path;
    t_img   img;
} t_texture;

typedef struct s_map
{
    t_texture   texture[TEXTURE_COUNT];
    t_color     floor_color;
    t_color     ceiling_color;
    char        **grid;
    int         width;
    int         height;
} t_map;

#endif
