#ifndef UTIL_STRUCT_H
#define UTIL_STRUCT_H

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
    GAME_INITIALIZATION_ERROR
}   t_error;

typedef enum e_texture
{
    NO,
    SO,
    EA,
    WE,
    TEXTURE_COUNT
}   t_texture;

#endif
