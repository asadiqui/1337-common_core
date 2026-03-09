/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:30:45 by asadiqui          #+#    #+#             */
/*   Updated: 2024/11/17 10:28:16 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	raycast_init_helper(t_data *data, t_raycast *raycast, int i)
{
	if (raycast->ray_dir_y[i] < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (data->player.y - raycast->map_y)
			* raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = (raycast->map_y + 1.0 - data->player.y)
			* raycast->delta_dist_y;
	}
}

void	raycast_init(t_data *data, t_raycast *raycast, int i)
{
	raycast->map_x = (int)data->player.x;
	raycast->map_y = (int)data->player.y;
	raycast->delta_dist_x = fabs(1 / raycast->ray_dir_x[i]);
	raycast->delta_dist_y = fabs(1 / raycast->ray_dir_y[i]);
	if (raycast->ray_dir_x[i] < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (data->player.x - raycast->map_x)
			* raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = (raycast->map_x + 1.0 - data->player.x)
			* raycast->delta_dist_x;
	}
	raycast_init_helper(data, raycast, i);
}

int	dda_loop(t_data *data, t_raycast *raycast)
{
	int	side;
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			side = 1;
		}
		if (data->map[raycast->map_y][raycast->map_x] == '1')
			hit = 1;
	}
	return (side);
}

float	distance_to_wall(t_data *data, t_raycast *raycast, int i)
{
	int		side;
	float	raw_dist;

	raycast_init(data, raycast, i);
	side = dda_loop(data, raycast);
	if (side == 0)
	{
		if (raycast->ray_dir_x[i] < 0)
			raycast->wall_sides[i] = 'w';
		else
			raycast->wall_sides[i] = 'e';
		raw_dist = (raycast->map_x - data->player.x + (1.0 - raycast->step_x)
				/ 2.0) / raycast->ray_dir_x[i];
	}
	else
	{
		if (raycast->ray_dir_y[i] < 0)
			raycast->wall_sides[i] = 'n';
		else
			raycast->wall_sides[i] = 's';
		raw_dist = (raycast->map_y - data->player.y + (1.0 - raycast->step_y)
				/ 2.0) / raycast->ray_dir_y[i];
	}
	return (raw_dist * BLOCK_SIZE);
}

void	cast_rays(t_data *data)
{
	t_raycast	raycast;
	float		player_angle;
	float		ray_angle;
	int			i;

	i = -1;
	raycast.distances = malloc(sizeof(float) * NUM_RAYS);
	gc_push(raycast.distances);
	raycast.wall_sides = malloc(sizeof(float) * NUM_RAYS);
	gc_push(raycast.wall_sides);
	raycast.ray_dir_x = malloc(sizeof(float) * NUM_RAYS);
	gc_push(raycast.ray_dir_x);
	raycast.ray_dir_y = malloc(sizeof(float) * NUM_RAYS);
	gc_push(raycast.ray_dir_y);
	player_angle = atan2(data->player.dir_y, data->player.dir_x);
	while (++i < NUM_RAYS)
	{
		ray_angle = player_angle - (FOV / 2) + (i * FOV / NUM_RAYS);
		raycast.ray_dir_x[i] = cos(ray_angle);
		raycast.ray_dir_y[i] = sin(ray_angle);
		raycast.distances[i] = distance_to_wall(data, &raycast, i)
			* cos(ray_angle - player_angle);
	}
	render_3d_view(data, &raycast);
	mlx_put_image_to_window(data->mlx, data->win_3d, data->render_img, 0, 0);
}
