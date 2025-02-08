/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisong <hisong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 01:17:19 by hisong            #+#    #+#             */
/*   Updated: 2025/02/09 01:17:19 by hisong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_STRUCT_H
# define UTIL_STRUCT_H

typedef enum e_texture_type
{
	TEXTURE_NORTH,
	TEXTURE_SOUTH,
	TEXTURE_EAST,
	TEXTURE_WEST,
	TEXTURE_COUNT
}	t_texture_type;

typedef enum e_error
{
	NO_ERROR,
	MALLOC_ERROR,
	OPEN_ERROR,
	READ_ERROR,
	ARG_ERROR,
	RESOLUTION_ERROR,
	TEXTURE_ERROR,
	COLOR_ERROR,
	MAP_ERROR,
	FILE_NAME_ERROR,
	MAP_WALL_ERROR,
	MAP_PLAYER_ERROR,
	MAP_CHAR_ERROR,
	MAP_SIZE_ERROR,
	MLX_INIT_ERROR,
	MLX_WINDOW_ERROR,
	MLX_IMAGE_ERROR,
	MLX_DATA_ADDR_ERROR,
	INVALID_ARGUMENTS,
	INVALID_FILE_EXTENSION,
	MAP_INITIALIZATION_ERROR,
	GAME_INITIALIZATION_ERROR,
	DUPLICATE_KEY_ERROR
}	t_error;

#endif
