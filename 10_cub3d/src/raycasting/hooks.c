/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:30:42 by asadiqui          #+#    #+#             */
/*   Updated: 2024/11/17 18:36:04 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_collision(t_data *data, float new_x, float new_y)
{
	int (grid_x), (grid_y), (player_grid_x), (player_grid_y);
	grid_x = (int)new_x;
	grid_y = (int)new_y;
	player_grid_x = (int)data->player.x;
	player_grid_y = (int)data->player.y;
	if (data->map[grid_y][grid_x] == '1' || data->map[grid_y][grid_x] == ' '
		|| data->map[grid_y][grid_x] == '\t')
		return (1);
	else if (grid_x > player_grid_x && grid_y < player_grid_y
		&& (data->map[player_grid_y][grid_x] == '1'
		&& data->map[grid_y][player_grid_x] == '1'))
		return (1);
	else if (grid_x < player_grid_x && grid_y < player_grid_y
		&& (data->map[player_grid_y][grid_x] == '1'
		&& data->map[grid_y][player_grid_x] == '1'))
		return (1);
	else if (grid_x > player_grid_x && grid_y > player_grid_y
		&& (data->map[player_grid_y][grid_x] == '1'
		&& data->map[grid_y][player_grid_x] == '1'))
		return (1);
	else if (grid_x < player_grid_x && grid_y > player_grid_y
		&& (data->map[player_grid_y][grid_x] == '1'
		&& data->map[grid_y][player_grid_x] == '1'))
		return (1);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		(ffreeee(1, data), _free(), exit(0));
	if (keycode == W)
		data->player.move_forward = 1;
	if (keycode == S)
		data->player.move_backward = 1;
	if (keycode == A)
		data->player.move_left = 1;
	if (keycode == D)
		data->player.move_right = 1;
	if (keycode == LEFT)
		data->player.rotate_left = 1;
	if (keycode == RIGHT)
		data->player.rotate_right = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == W)
		data->player.move_forward = 0;
	if (keycode == S)
		data->player.move_backward = 0;
	if (keycode == A)
		data->player.move_left = 0;
	if (keycode == D)
		data->player.move_right = 0;
	if (keycode == LEFT)
		data->player.rotate_left = 0;
	if (keycode == RIGHT)
		data->player.rotate_right = 0;
	return (0);
}

void	update_player(t_data *data)
{
	move_forward_backward(data);
	move_left_right(data);
	rotate_left_right(data);
}
