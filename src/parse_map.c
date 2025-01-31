#include "cub3d.h"

static int is_valid_map_char(char c)
{
    return (c == '0' || c == '1' || c == 'N' || 
            c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

static int validate_map_chars(char **grid, int height, int width)
{
    int i;
    int j;
    int player_count;

    player_count = 0;
    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (!is_valid_map_char(grid[i][j]))
            {
                ft_putstr_fd("Invalid character '", 2);
                ft_putchar_fd(grid[i][j], 2);
                ft_putstr_fd("' at line ", 2);
                ft_putnbr_fd(i + 1, 2);
                ft_putstr_fd(", column ", 2);
                ft_putnbr_fd(j + 1, 2);
                ft_putstr_fd("\n", 2);
                error_handler(MAP_CHAR_ERROR);
                return (0);
            }
            if (grid[i][j] == 'N' || grid[i][j] == 'S' ||
                grid[i][j] == 'E' || grid[i][j] == 'W')
                player_count++;
            j++;
        }
        i++;
    }
    if (player_count != 1)
    {
        error_handler(MAP_PLAYER_ERROR);
        return (0);
    }
    return (1);
}

static int check_walls(char **grid, int height, int width)
{
    int i;
    int j;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (grid[i][j] != '1' && grid[i][j] != ' ')
            {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                {
                    error_handler(MAP_WALL_ERROR);
                    return (0);
                }
                if (i > 0 && i < height - 1 && j > 0 && j < width - 1 &&
                    (grid[i-1][j] == ' ' || grid[i+1][j] == ' ' ||
                    grid[i][j-1] == ' ' || grid[i][j+1] == ' '))
                {
                    error_handler(MAP_WALL_ERROR);
                    return (0);
                }
            }
            j++;
        }
        i++;
    }
    return (1);
}

static int count_map_lines(char **lines)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (lines[i])
    {
        if (ft_strlen(lines[i]) > 0)
            count++;
        i++;
    }
    return (count);
}

static int get_map_width(char **lines)
{
    int max_width;
    int current_width;
    int i;

    max_width = 0;
    i = 0;
    while (lines[i])
    {
        current_width = ft_strlen(lines[i]);
        if (current_width > max_width)
            max_width = current_width;
        i++;
    }
    return (max_width);
}

static char **create_map_grid(char **lines, int height, int width)
{
    char **grid;
    int i;
    int j;

    grid = (char **)malloc(sizeof(char *) * (height + 1));
    if (!grid)
    {
        error_handler(MALLOC_ERROR);
        return (NULL);
    }
    i = 0;
    while (i < height)
    {
        grid[i] = (char *)malloc(sizeof(char) * (width + 1));
        if (!grid[i])
        {
            error_handler(MALLOC_ERROR);
            while (--i >= 0)
                free(grid[i]);
            free(grid);
            return (NULL);
        }
        ft_memset(grid[i], ' ', width);
        grid[i][width] = '\0';
        j = 0;
        while (lines[i][j] && j < width)
        {
            grid[i][j] = lines[i][j];
            j++;
        }
        i++;
    }
    grid[height] = NULL;
    return (grid);
}

int parse_map(char **lines, t_map *map)
{
    int height;
    int width;

    height = count_map_lines(lines);
    if (height < 3)
    {
        error_handler(MAP_SIZE_ERROR);
        return (0);
    }
    width = get_map_width(lines);
    if (width < 3)
    {
        error_handler(MAP_SIZE_ERROR);
        return (0);
    }
    map->grid = create_map_grid(lines, height, width);
    if (!map->grid)
        return (0);
    map->height = height;
    map->width = width;
    if (!validate_map_chars(map->grid, height, width))
        return (0);
    if (!check_walls(map->grid, height, width))
        return (0);
    return (1);
}
