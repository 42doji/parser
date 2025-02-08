/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisong <hisong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:42:13 by hisong            #+#    #+#             */
/*   Updated: 2025/02/09 01:07:08 by hisong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_number(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (TEXTURE_WEST);
		return (TEXTURE_EAST);
	}
	if (ray->ray_dir_y > 0)
		return (TEXTURE_SOUTH);
	return (TEXTURE_NORTH);
}
