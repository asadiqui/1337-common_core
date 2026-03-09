/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:31:14 by asadiqui          #+#    #+#             */
/*   Updated: 2024/11/16 00:31:14 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

typedef struct s_data	t_data;

typedef struct s_raycast
{
	float				*ray_dir_x;
	float				*ray_dir_y;
	float				*distances;
	char				*wall_sides;
	int					map_x;
	int					map_y;
	double				wall_x;
	float				delta_dist_x;
	float				delta_dist_y;
	int					step_x;
	int					step_y;
	float				side_dist_x;
	float				side_dist_y;
}						t_raycast;

void					cast_rays(t_data *data);
void					line_put(t_data *data, float end_x, float end_y);

#endif