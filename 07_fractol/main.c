/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:17:18 by asadiqui          #+#    #+#             */
/*   Updated: 2024/05/14 14:15:21 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error_msg(void)
{
	write(2, "Usuage:\n./fractol [m]\t\t(mandelbrot)\
		\n./fractol [s]\t\t(burning ship)\
		\n./fractol [j [x y]]\t(julia with valid decimal coordinates)\n", 129);
	exit (EXIT_FAILURE);
}

static char	*enum_to_str(t_data *data)
{
	char	*str;

	if (data->param == MANDELBROT)
		str = "Mandelbrot Fractal";
	else if (data->param == JULIA)
		str = "Julia Fractal";
	else
		str = "Burning Ship Fractal";
	return (str);
}

static t_params	str_to_enum(char *str)
{
	if (!ft_strcmp(str, "m") || !ft_strcmp(str, "M") \
		|| !ft_strcmp(str, "mandelbrot") || !ft_strcmp(str, "Mandelbrot") \
		|| !ft_strcmp(str, "MANDELBROT"))
		return (MANDELBROT);
	else if (!ft_strcmp(str, "j") || !ft_strcmp(str, "J") \
		|| !ft_strcmp(str, "julia") || !ft_strcmp(str, "Julia") \
		|| !ft_strcmp(str, "JULIA"))
		return (JULIA);
	else if (!ft_strcmp(str, "s") || !ft_strcmp(str, "S") \
		|| !ft_strcmp(str, "ship") || !ft_strcmp(str, "Ship") \
		|| !ft_strcmp(str, "SHIP"))
		return (SHIP);
	return (UNKNOWN);
}

static void	param_handling(int ac, char **av, t_data *data)
{
	if (ac == 1)
		error_msg();
	data->param = str_to_enum(av[1]);
	if (data->param == UNKNOWN || ac > 4 || (data->param == JULIA && ac != 4) \
		|| ((data->param == MANDELBROT || data->param == SHIP) && ac != 2))
		error_msg();
	if (data->param == JULIA)
	{
		data->juliar = ft_atoi(av[2]);
		data->juliai = ft_atoi(av[3]);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	param_handling(ac, av, &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, enum_to_str(&data));
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line, &data.end);
	data.zoom = 1;
	data.move_x = -0.5;
	if (data.param == JULIA)
		data.move_x = 0;
	data.move_y = 0;
	data.colorshift = 1;
	draw_fractal(&data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, ft_exit, &data);
	mlx_loop_hook(data.mlx, color_shift, &data);
	write(2, "Controls:\nZoom\t\t: mouse; +; -\nMove View\t: arrows\
		\nReset View\t: r\nClosw Window\t: Esc\n", 85);
	mlx_loop(data.mlx);
	return (0);
}
