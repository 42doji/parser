/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:12:42 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:12:43 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "util_struct.h"
# include "map_struct.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

t_map	*init_map(char *file_name);
void	error_handler(t_error error);
int		parse_cub_file(char *file_name, t_map *map);
void	free_map_resources(t_game *game, t_map *map);
int		parse_map(char **lines, t_map *map);
int		is_valid_extension(char *file_name, char *extension);
int		is_valid_file(char *file_name);

// Game functions
int		init_game(t_game *game, t_map *map);
void	init_player(t_game *game);
int		load_textures(t_game *game);
int		game_loop(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		close_window(t_game *game);
void	cast_rays(t_game *game);
void	draw_frame(t_game *game);
void    put_pixel(t_game *game, int x, int y, int color);

#endif
