/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:57:58 by merrahal          #+#    #+#             */
/*   Updated: 2024/11/17 08:59:48 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	x_button(t_data *data)
{
	ffreeee(1, data);
	_free();
	exit(0);
}

void	move_forward_backward(t_data *data)
{
	float	new_x;
	float	new_y;

	if (data->player.move_forward)
	{
		new_x = data->player.x + data->player.dir_x * MOVE_SPEED;
		new_y = data->player.y + data->player.dir_y * MOVE_SPEED;
		if (!is_collision(data, new_x, new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
	if (data->player.move_backward)
	{
		new_x = data->player.x - data->player.dir_x * MOVE_SPEED;
		new_y = data->player.y - data->player.dir_y * MOVE_SPEED;
		if (!is_collision(data, new_x, new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
}

void	move_left_right(t_data *data)
{
	float	new_x;
	float	new_y;

	if (data->player.move_left)
	{
		new_x = data->player.x + data->player.dir_y * MOVE_SPEED;
		new_y = data->player.y - data->player.dir_x * MOVE_SPEED;
		if (!is_collision(data, new_x, new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
	if (data->player.move_right)
	{
		new_x = data->player.x - data->player.dir_y * MOVE_SPEED;
		new_y = data->player.y + data->player.dir_x * MOVE_SPEED;
		if (!is_collision(data, new_x, new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
}

void	rotate_left_right(t_data *data)
{
	float	old_dir_x;

	if (data->player.rotate_left)
	{
		old_dir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(-ROT_SPEED)
			- data->player.dir_y * sin(-ROT_SPEED);
		data->player.dir_y = old_dir_x * sin(-ROT_SPEED) + data->player.dir_y
			* cos(-ROT_SPEED);
	}
	if (data->player.rotate_right)
	{
		old_dir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(ROT_SPEED)
			- data->player.dir_y * sin(ROT_SPEED);
		data->player.dir_y = old_dir_x * sin(ROT_SPEED) + data->player.dir_y
			* cos(ROT_SPEED);
	}
}
