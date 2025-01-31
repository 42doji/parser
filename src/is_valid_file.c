/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:21:06 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:21:06 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_file(char *file_name)
{
	int	fd;

	if (!file_name)
	{
		error_handler(OPEN_ERROR, NULL, NULL);
		return (0);
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		error_handler(OPEN_ERROR, NULL, NULL);
		return (0);
	}
	close(fd);
	return (1);
}
