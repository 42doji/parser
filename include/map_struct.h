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
#define MAP_STRUCT_H

#include "render_struct.h"

typedef struct s_texture_path
{
	char *path;
	t_img img;
} t_texture_path;

typedef struct s_map
{
	t_texture_path texture[4];
	int floor_color[3];
	int ceiling_color[3];
	char **grid;
	int width;
	int height;
} t_map;

#endif
