#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "util_struct.h"
#include "map_struct.h"

t_map *init_map(char *file_name);
void error_handler(t_error error);
int parse_cub_file(char *file_name, t_map *map);
void free_map_resources(t_map *map);
int parse_map(char **lines, t_map *map);
int is_valid_extension(char *file_name, char *extension);
int is_valid_file(char *file_name);

#endif //CUB3D_H
