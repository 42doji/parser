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
    MAP_SIZE_ERROR
} t_error;

typedef enum e_texture
{
    NO,
    SO,
    EA,
    WE,
    TEXTURE_COUNT
} t_texture;

#endif
