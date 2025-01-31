#include "cub3d.h"

void free_split(char **split)
{
    size_t i;

    if (!split)
        return ;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

size_t ft_splitlen(char **split)
{
    size_t len;

    if (!split)
        return (0);
    len = 0;
    while (split[len])
        len++;
    return (len);
}
