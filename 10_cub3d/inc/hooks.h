/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:31:04 by asadiqui          #+#    #+#             */
/*   Updated: 2024/11/17 18:36:14 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "cub3d.h"

typedef struct s_data	t_data;
int						key_press(int keycode, t_data *data);
int						key_release(int keycode, t_data *data);
void					update_player(t_data *data);
int						is_collision(t_data *data, float new_x, float new_y);

#endif