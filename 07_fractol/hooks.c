/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:17:14 by asadiqui          #+#    #+#             */
/*   Updated: 2024/05/14 14:47:37 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	color_shift(t_data *data)
{
	int	i;
	int	pseudo_sleep;

	pseudo_sleep = INT_MAX / 10;
	i = 0;
	while (i < pseudo_sleep)
		i++;
	data->colorshift++;
	draw_fractal(data);
	return (0);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	mouse_hook(int mousecode, int x, int y, t_data *data)
{
	double	cr;
	double	ci;

	if (mousecode == 4 || mousecode == 5)
	{
		cr = 1.33 * ((double)x * 2.4 / WIDTH - 1.2) \
			* data->zoom + data->move_x;
		ci = 1.0 * ((double)y * 2.4 / HEIGHT - 1.2) \
			* data->zoom + data->move_y;
		if (mousecode == 4)
		{
			data->zoom *= 1.1;
			data->move_x -= 0.1 * (cr - data->move_x);
			data->move_y -= 0.1 * (ci - data->move_y);
		}
		else if (mousecode == 5)
		{
			data->zoom /= 1.1;
			data->move_x -= (1 / 1.1 - 1) * (cr - data->move_x);
			data->move_y -= (1 / 1.1 - 1) * (ci - data->move_y);
		}
	}
	draw_fractal(data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == RESET)
	{
		data->zoom = 1;
		data->move_x = -0.5;
		if (data->param == JULIA)
			data->move_x = 0;
		data->move_y = 0;
	}
	else if (keycode == ESC)
		return (ft_exit(data));
	else if (keycode == UP)
		data->move_y += data->zoom;
	else if (keycode == DOWN)
		data->move_y -= data->zoom;
	else if (keycode == RIGHT)
		data->move_x -= data->zoom;
	else if (keycode == LEFT)
		data->move_x += data->zoom;
	else if (keycode == PLUS)
		mouse_hook(5, WIDTH / 2, HEIGHT / 2, data);
	else if (keycode == MINUS)
		mouse_hook(4, WIDTH / 2, HEIGHT / 2, data);
	draw_fractal(data);
	return (0);
}
