/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:30:59 by asadiqui          #+#    #+#             */
/*   Updated: 2024/11/17 16:03:12 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_parsing.h"
# include "hooks.h"
# include "raycasting.h"
# include "render_3d.h"
# include "textures.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define BLOCK_SIZE 30
# define MOVE_SPEED 0.0075
# define ROT_SPEED 0.0075
# define WIDTH 1000
# define HEIGHT 500
# define PROJECTION_PLANE_DIST 50
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define SPACE 32
# define FOV 1.04719755
# define NUM_RAYS 1000

typedef struct s_texture
{
	char			*path;
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_length;
	int				endian;

}					t_texture;

typedef struct s_player
{
	float			x;
	float			y;
	float			dir_x;
	float			dir_y;
	int				move_forward;
	int				move_backward;
	int				move_left;
	int				move_right;
	int				rotate_left;
	int				rotate_right;
}					t_player;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	void			*win_3d;
	void			*render_img;
	char			*render_img_addr;
	char			**map;
	int				map_width;
	int				map_height;
	int				bpp;
	int				line_length;
	int				endian;
	unsigned int	ceiling;
	unsigned int	floor;
	t_player		player;
	t_texture		texture_no;
	t_texture		texture_ea;
	t_texture		texture_so;
	t_texture		texture_we;
	int				last_x;
}					t_data;

void				move_forward_backward(t_data *data);
void				move_left_right(t_data *data);
void				rotate_left_right(t_data *data);
int					x_button(t_data *data);
int					game_loop(t_data *data);
void				ffreeee(int i, t_data *data);
void				initialise_textures(t_data *data, t_texture *texture,
						char *path);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_data				**get_data(void);

#endif