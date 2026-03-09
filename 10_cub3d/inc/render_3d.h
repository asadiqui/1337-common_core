/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:31:17 by asadiqui          #+#    #+#             */
/*   Updated: 2024/11/16 00:31:17 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_3D_H
# define RENDER_3D_H

# include "cub3d.h"

typedef struct s_data	t_data;

void					render_3d_view(t_data *data, t_raycast *raycast);

#endif