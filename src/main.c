/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:21:10 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:21:11 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    t_map   *map;

    if (argc != 2)
    {
        error_handler(ARG_ERROR);
        return (EXIT_FAILURE);
    }
    if (!is_valid_extension(argv[1], ".cub"))
    {
        error_handler(FILE_NAME_ERROR);
        return (EXIT_FAILURE);
    }
    if (!is_valid_file(argv[1]))
    {
        return (EXIT_FAILURE);
    }
    map = init_map(argv[1]);
    if (!map)
        return (EXIT_FAILURE);
    // 게임 초기화 및 실행 로직 추가 필요
    free_map_resources(map);
    return (0);
}
