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