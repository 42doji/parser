#include "cub3d.h"

int main(int argc, char **argv)
{
    t_map *map;

    if (argc != 2)
    {
        error_handler(ARG_ERROR);
    }
    if (!is_valid_extension(argv[1], ".cub"))
    {
        error_handler(FILE_NAME_ERROR);
    }
    if (!is_valid_file(argv[1]))
    {
        // is_valid_file 함수 내에서 에러 처리
        return (EXIT_FAILURE);
    }
    map = init_map(argv[1]);
    if (!map)
        return (EXIT_FAILURE);
    // 게임 초기화 및 실행 로직 추가 필요
    free(map);
    return (0);
}
