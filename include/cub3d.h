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
# include "render_struct.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

t_map	*init_map(char *file_name);
void	error_handler(t_error error, t_game *game, t_map *map);
int		parse_cub_file(char *file_name, t_map *map, t_game *game);
void	free_map_resources(t_game *game, t_map *map);
int		parse_map(char **lines, t_map *map, t_game *game);
int		is_valid_extension(char *file_name, char *extension);
int		is_valid_file(char *file_name);
int		init_game(t_game *game, t_map *map);
void	init_player(t_game *game);
int     init_map_values(t_map *map);
void    cleanup_map(t_map *map);
void    cleanup_game(t_game *game);
void    set_player_direction(t_game *game, char direction);
int     check_walls(char **grid, t_map *map, t_game *game);
int     process_line(char *line, t_map *map, char ***map_lines, int *map_size);
int     check_settings_complete(t_map *map);
int     parse_settings(const char *line, t_map *map, t_game *game);
int     append_map_line(char ***map_lines, int *map_size, char *line);
void    trim_line_endings(char *line);
int     parse_texture(const char *line, t_map *map, int texture_index, const char *key, t_game *game);
int     validate_map_chars(char **grid, int height, int width);
int     is_valid_map_char(char c);
int     init_grid_row(char **grid, int i, int width);
char    **create_map_grid(char **lines, int height, int width);
int		load_textures(t_game *game);
int		game_loop(t_game *game);
int		handle_keypress(int keycode, void *param);
int		handle_keyrelease(int keycode, void *param);
int		close_window(t_game *game);
void	cast_rays(t_game *game);
void	draw_frame(t_game *game);
void    update_game_state(t_game *game, double elapsed);
void    move_right(t_game *game, double speed);
void    move_left(t_game *game, double speed);
void    move_backward(t_game *game, double speed);
void    move_forward(t_game *game, double speed);
void    perform_dda(t_game *game, t_ray *ray);
void    draw_wall_line(t_game *game, t_ray *ray, int x);
int     get_texture_number(t_ray *ray);
int     get_texture_color(t_img *texture, int x, int y);
void    calculate_step_and_side_dist(t_game *game, t_ray *ray);
void    calculate_wall_distance(t_game *game, t_ray *ray);
void    init_ray(t_game *game, t_ray *ray, int x);
void    put_pixel(t_img *img, int x, int y, int color);
void    get_next_line_cleanup(int fd);

#endif
