/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:30:48 by asadiqui          #+#    #+#             */
/*   Updated: 2024/11/17 16:20:28 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_texture	*select_texture(t_data *data, char c)
{
	if (c == 'n')
		return (&data->texture_no);
	else if (c == 'e')
		return (&data->texture_ea);
	else if (c == 's')
		return (&data->texture_so);
	return (&data->texture_we);
}

void	render_3d_view(t_data *data, t_raycast *raycast)
{
	t_texture	*texture;
	int			wall_height;
	int			screen_x;
	int			start_y;
	int			end_y;

	int (i), (y);
	i = -1;
	while (++i < NUM_RAYS)
	{
		wall_height = (int)((HEIGHT / raycast->distances[i])
				* PROJECTION_PLANE_DIST);
		start_y = (HEIGHT / 2) - (wall_height / 2);
		end_y = (HEIGHT / 2) + (wall_height / 2);
		screen_x = (i * WIDTH) / NUM_RAYS;
		y = -1;
		while (++y < start_y)
			my_mlx_pixel_put(data, screen_x, y, data->ceiling);
		texture = select_texture(data, raycast->wall_sides[i]);
		render_wall_slice(data, raycast, texture, i);
		y = end_y - 1;
		while (++y < HEIGHT)
			my_mlx_pixel_put(data, screen_x, y, data->floor);
	}
}
