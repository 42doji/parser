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

typedef struct s_map
{
	char *texture[4]; // 벽 텍스처 (NO, SO, EA, WE)
	int floor_color[3]; // 바닥 색상 (RGB)
	int ceiling_color[3]; // 천장 색상 (RGB)
	char **grid; // 맵을 2차원 배열로 저장
	int width; // 맵의 너비
	int height; // 맵의 높이
} t_map;

#endif
