/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:30:37 by asadiqui          #+#    #+#             */
/*   Updated: 2024/11/17 18:42:04 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = data->render_img_addr + (y * data->line_length + x * (data->bpp
				/ 8));
	*(unsigned int *)pixel = color;
}

int	game_loop(t_data *data)
{
	mlx_clear_window(data->mlx, data->win_3d);
	update_player(data);
	cast_rays(data);
	return (0);
}

void	initialise_textures(t_data *data, t_texture *texture, char *path)
{
	texture->path = path;
	texture->img = mlx_xpm_file_to_image(data->mlx, texture->path,
			&(texture->width), &(texture->height));
	if (!texture->img)
	{
		printf("Failed to load texture\n");
		(ffreeee(1, data), _free(), exit(1));
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_length, &texture->endian);
}

int	initialise_data(t_data *data, t_all *parsed)
{
	if (!parsed)
		return (1);
	data->render_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->render_img)
		return (1);
	data->render_img_addr = mlx_get_data_addr(data->render_img, &data->bpp,
			&data->line_length, &data->endian);
	if (!data->render_img_addr)
		return (1);
	data->map = parsed->two_d_map;
	data->map_width = parsed->mini_map_width;
	data->map_height = parsed->mini_map_height;
	data->player = (t_player){};
	data->player.x = parsed->player.column + 0.5;
	data->player.y = parsed->player.row + 0.5;
	data->player.dir_x = parsed->player.dir_x;
	data->player.dir_y = parsed->player.dir_y;
	initialise_textures(data, &data->texture_no, parsed->textures.no);
	initialise_textures(data, &data->texture_ea, parsed->textures.ea);
	initialise_textures(data, &data->texture_so, parsed->textures.so);
	initialise_textures(data, &data->texture_we, parsed->textures.we);
	data->ceiling = (parsed->c.r << 16) | (parsed->c.g << 8) | parsed->c.b;
	data->floor = (parsed->f.r << 16) | (parsed->f.g << 8) | parsed->f.b;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){};
	data.mlx = mlx_init();
	gc_push(data.mlx);
	if (!data.mlx)
		return (1);
	(*get_data()) = &data;
	if (initialise_data(&data, parser(&data, argc, argv)))
	{
		printf("problem with mlx initialization or mlx images\n");
		(_free(), exit(1));
	}
	data.win_3d = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3D");
	cast_rays(&data);
	mlx_hook(data.win_3d, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win_3d, 3, 1L << 1, key_release, &data);
	mlx_hook(data.win_3d, 17, 0, x_button, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	_free();
	return (0);
}
