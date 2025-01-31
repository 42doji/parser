/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:20:54 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:20:55 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler(t_error error)
{
    const char *error_msg[] = {
        "Error: No error",
        "Error: Memory allocation failed",
        "Error: Failed to open file",
        "Error: Failed to read file", 
        "Error: Invalid arguments",
        "Error: Invalid resolution",
        "Error: Invalid texture",
        "Error: Invalid color",
        "Error: Invalid map",
        "Error: Invalid file name",
        "Error: Invalid map walls",
        "Error: Invalid number of players",
        "Error: Invalid map characters",
        "Error: Map size is too small"
    };
    if (error >= 0 && error < sizeof(error_msg) / sizeof(error_msg[0]))
        ft_putendl_fd((char *)error_msg[error], 2);
    else
        ft_putendl_fd("Error: Unknown error", 2);
}
