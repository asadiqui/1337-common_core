/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:39:47 by asadiqui          #+#    #+#             */
/*   Updated: 2024/05/15 18:05:04 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/*##############################*|
|*			HEADERS				*|
|*##############################*/

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "float.h"
# include <limits.h>
# include <stdio.h>
/*##############################*|
|*			MACROS				*|
|*##############################*/

# define WIDTH		960//1440//480//960
# define HEIGHT		720//1080//360//720
# define MAXITER	50
# define MAXITERJ	250
# define LEFT		65361
# define UP			65362
# define RIGHT		65363
# define DOWN		65364
# define RESET		114
# define ESC		65307
# define PLUS		65451
# define MINUS		65453
// # define AESTRICK	65450

/*##############################*|
|*			STRUCTS/ENUMS		*|
|*##############################*/

typedef enum e_params
{
	MANDELBROT,
	SHIP,
	JULIA,
	UNKNOWN,
}	t_params;

typedef struct data
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bpp;
	int			line;
	int			end;
	int			x;
	int			y;
	t_params	param;
	double		juliar;
	double		juliai;
	int			color;
	double		zoom;
	double		move_x;
	double		move_y;
	int			colorshift;
}	t_data;

/*##############################*|
|*				MAIN			*|
|*##############################*/

// int				main(int ac, char **av);
// static void		param_handling(int ac, char **av, t_data *data);
// static t_params	str_to_enum(char *str);
// static char		*enum_to_str(t_data *data)
void				error_msg(void);

/*##############################*|
|*			FRACTALS			*|
|*##############################*/

void				draw_fractal(t_data *data);
// static void		calculate_mandelbrot(t_data *data, double cr, double ci);
// static void		calculate_julia(t_data *data, double cr, double ci);
// static void		calculate_ship(t_data *data, double cr, double ci);
int					generate_colors(int iter, t_data *data);

/*##############################*|
|*				HOOKS			*|
|*##############################*/

int					key_hook(int keycode, t_data *data);
int					mouse_hook(int mousecode, int x, int y, t_data *data);
int					color_shift(t_data *data);
int					ft_exit(t_data *data);

/*##############################*|
|*				UTILS			*|
|*##############################*/

int					ft_strcmp(const char *s1, const char *s2);
double				ft_atoi(const char *str);
// static int		retrieve_sign(const char **str)

#endif