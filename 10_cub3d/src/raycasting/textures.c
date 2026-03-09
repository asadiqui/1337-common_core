/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:30:51 by asadiqui          #+#    #+#             */
/*   Updated: 2024/11/17 18:36:51 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render_wall_slice(t_data *data, t_raycast *raycast, t_texture *texture,
		int i)
{
	int				wall_height;
	int				draw_start;
	int				draw_end;
	char			*pixel;
	unsigned int	color;

	int (x), (y), (tex_x), (tex_y);
	x = (i * WIDTH) / NUM_RAYS;
	tex_x = calculate_texture_x(data, texture, raycast, i);
	wall_height = (int)((HEIGHT / raycast->distances[i])
			* PROJECTION_PLANE_DIST);
	draw_start = (HEIGHT / 2) - (wall_height / 2);
	draw_end = (HEIGHT / 2) + (wall_height / 2);
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = ((y - draw_start) * texture->height) / (draw_end - draw_start);
		pixel = texture->addr + (tex_y * texture->line_length + tex_x
				* (texture->bpp / 8));
		color = *(unsigned int *)pixel;
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}

int	calculate_texture_x(t_data *data, t_texture *texture, t_raycast *raycast,
		int i)
{
	int (tex_x);
	float (wall_x), (ray_dir);
	if (raycast->wall_sides[i] == 'w' || raycast->wall_sides[i] == 'e')
	{
		ray_dir = raycast->ray_dir_y[i];
		wall_x = data->player.y + (raycast->distances[i] / cos(-(FOV / 2) + (i
						* FOV / NUM_RAYS)) / BLOCK_SIZE) * ray_dir;
		if (raycast->ray_dir_x[i] < 0)
			wall_x = 1 - wall_x;
	}
	else
	{
		ray_dir = raycast->ray_dir_x[i];
		wall_x = data->player.x + (raycast->distances[i] / cos(-(FOV / 2) + (i
						* FOV / NUM_RAYS)) / BLOCK_SIZE) * ray_dir;
		if (raycast->ray_dir_y[i] > 0)
			wall_x = 1 - wall_x;
	}
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (float)texture->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= texture->width)
		tex_x = texture->width - 1;
	return (tex_x);
}

t_data	**get_data(void)
{
	static t_data	*data_;

	return (&data_);
}

void	ffreeee(int i, t_data *data)
{
	if (i)
	{
		if (data->render_img)
			mlx_destroy_image(data->mlx, data->render_img);
		if (data->texture_ea.img)
			mlx_destroy_image(data->mlx, data->texture_ea.img);
		if (data->texture_no.img)
			mlx_destroy_image(data->mlx, data->texture_no.img);
		if (data->texture_we.img)
			mlx_destroy_image(data->mlx, data->texture_we.img);
		if (data->texture_so.img)
			mlx_destroy_image(data->mlx, data->texture_so.img);
		if (data->win_3d)
			mlx_destroy_window(data->mlx, data->win_3d);
	}
	mlx_destroy_display(data->mlx);
}
