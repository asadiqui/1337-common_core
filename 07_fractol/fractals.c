/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:17:10 by asadiqui          #+#    #+#             */
/*   Updated: 2024/05/15 18:03:41 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	generate_colors(int iter, t_data *data)
{
	int	r;
	int	g;
	int	b;

	if (iter == MAXITER && data->param != JULIA)
		return (0x0);
	else if (iter == MAXITERJ && data->param == JULIA)
		return (0x0);
	r = (iter * 5 * data->colorshift) % 256;
	g = (iter * 10 * data->colorshift) % 256;
	b = (iter * 15 * data->colorshift) % 256;
	return ((r << 16) | (g << 8) | b);
}

static void	calculate_julia(t_data *data, double cr, double ci)
{
	int		iter;
	double	tmp;
	char	*pxl;

	iter = 0;
	while (iter < MAXITERJ && cr * cr + ci * ci <= 4.0)
	{
		tmp = cr * cr - ci * ci + data->juliar;
		ci = 2 * cr * ci + data->juliai;
		cr = tmp;
		iter++;
	}
	data->color = generate_colors(iter, data);
	pxl = data->addr + data->y * data->line + data->x * data->bpp / 8;
	*(unsigned int *)pxl = data->color;
}

static void	calculate_ship(t_data *data, double cr, double ci)
{
	int		iter;
	double	zr;
	double	zi;
	double	tmp;
	char	*pxl;

	iter = 0;
	zr = 0.0;
	zi = 0.0;
	while (iter < MAXITER && zr * zr + zi * zi <= 4.0)
	{
		if (zr < 0.0)
			zr *= -1.0;
		if (zi < 0.0)
			zi *= -1.0;
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	data->color = generate_colors(iter, data);
	pxl = data->addr + data->y * data->line + data->x * data->bpp / 8;
	*(unsigned int *)pxl = data->color;
}

static void	calculate_mandelbrot(t_data *data, double cr, double ci)
{
	int		iter;
	double	zr;
	double	zi;
	double	tmp;
	char	*pxl;

	iter = 0;
	zr = 0.0;
	zi = 0.0;
	while (iter < MAXITER && zr * zr + zi * zi <= 4.0)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	data->color = generate_colors(iter, data);
	pxl = data->addr + data->y * data->line + data->x * data->bpp / 8;
	*(unsigned int *)pxl = data->color;
}

void	draw_fractal(t_data *data)
{
	double	cr;
	double	ci;

	data->y = 0;
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			cr = 1.33 * ((double)data->x * 2.4 / WIDTH - 1.2) \
				* data->zoom + data->move_x;
			ci = 1.0 * ((double)data->y * 2.4 / HEIGHT - 1.2) \
				* data->zoom + data->move_y;
			if (data->param == MANDELBROT)
				calculate_mandelbrot(data, cr, ci);
			else if (data->param == SHIP)
				calculate_ship(data, cr, ci);
			else if (data->param == JULIA)
				calculate_julia(data, -1 * cr, ci);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
