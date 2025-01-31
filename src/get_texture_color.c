#include "cub3d.h"


int	get_texture_color(t_img *texture, int x, int y)
{
	char	*pixel;

	pixel = texture->addr + (y * texture->line_length +
		x * (texture->bits_per_pixel / 8));
	return (*(unsigned int*)pixel);
}