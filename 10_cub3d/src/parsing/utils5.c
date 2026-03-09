/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:44:08 by merrahal          #+#    #+#             */
/*   Updated: 2024/11/17 17:29:42 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_parsing.h"

void	set_player_col_row(t_all *all, int i, int j)
{
	if (all->two_d_map[i][j] == 'N' || all->two_d_map[i][j] == 'S'
		|| all->two_d_map[i][j] == 'E' || all->two_d_map[i][j] == 'W')
	{
		all->player.row = i + 0;
		all->player.column = j + 0;
	}
}

void	set_player_direction(t_all *all)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	all->player.dir_x = 0;
	all->player.dir_y = 0;
	while (all->two_d_map[i])
	{
		j = 0;
		while (j < all->mini_map_width)
		{
			set_player_col_row(all, i, j);
			if (all->two_d_map[i][j] == 'N')
				all->player.dir_y = -1;
			else if (all->two_d_map[i][j] == 'S')
				all->player.dir_y = 1;
			else if (all->two_d_map[i][j] == 'E')
				all->player.dir_x = 1;
			else if (all->two_d_map[i][j] == 'W')
				all->player.dir_x = -1;
			j++;
		}
		i++;
	}
}

int	parse_f_c_helper1(char **splitted2, t_all *all)
{
	if (!splitted2[1] || splitted2[2])
		return (ft_putstr_fd(RED "Error: bad texture\n" ENDC, 2), FAILURE);
	if (!ft_strncmp(splitted2[0], "NO", 3) || !ft_strncmp(splitted2[0], "SO", 3)
		|| !ft_strncmp(splitted2[0], "EA", 3) || !ft_strncmp(splitted2[0], "WE",
			3))
	{
		if (finish_with_xpm(splitted2[1]) == FAILURE)
			return (ft_putstr_fd(RED "Error: bad extension\
				(.xpm)\n" ENDC, 2), FAILURE);
		ft_open(all, splitted2);
	}
	if (!ft_strncmp(splitted2[0], "F", 2) || !ft_strncmp(splitted2[0], "C", 2))
	{
		if (count_q(all, splitted2) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	parse_f_c(t_all *all)
{
	int	i;

	i = 0;
	char **(splitted), **(splitted2);
	while (all->full_map[i] && i < 6)
	{
		splitted2 = ft_split_multi(all->full_map[i], " \t");
		if (parse_f_c_helper1(splitted2, all))
			return (FAILURE);
		splitted = ft_split_multi(all->full_map[i], " \t,");
		if (!ft_strncmp(splitted[0], "F", 2) || !ft_strncmp(splitted[0], "C",
				2))
		{
			if (f_c_are_valid(all, splitted) == FAILURE)
				return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}
