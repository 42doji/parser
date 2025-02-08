/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisong <hisong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:48:33 by hisong            #+#    #+#             */
/*   Updated: 2025/02/09 00:48:33 by hisong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	process_line(char *line, t_map *map, char ***map_lines, int *map_size)
{
	trim_line_endings(line);
	if (ft_strlen(line) > 0)
	{
		if (!check_settings_complete(map))
		{
			if (!parse_settings(line, map))
				return (0);
		}
		else
		{
			if (!append_map_line(map_lines, map_size, line, map))
				return (0);
		}
	}
	return (1);
}
