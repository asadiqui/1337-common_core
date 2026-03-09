/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:31:21 by asadiqui          #+#    #+#             */
/*   Updated: 2024/11/17 00:02:24 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "cub3d.h"

typedef struct s_texture	t_texture;

void						render_wall_slice(t_data *data, t_raycast *raycast,
								t_texture *texture, int i);
int							calculate_texture_x(t_data *data,
								t_texture *texture, t_raycast *raycast, int i);

#endif
