/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:22:29 by merrahal          #+#    #+#             */
/*   Updated: 2024/11/17 16:17:10 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_parsing.h"

int	check_white_space_in_the_mini_map(t_all *all)
{
	int		i;
	char	*trimmed;

	all->mini_map_height = 1;
	all->mini_map_width = 1;
	i = 0;
	while (all->full_map2[i])
	{
		trimmed = ft_strtrim(all->full_map2[i], " \t");
		gc_push(trimmed);
		if (!ft_strncmp(trimmed, all->full_map[6], ft_strlen(all->full_map[6])))
			break ;
		i++;
	}
	if (check_nl_in_mini_map(trimmed, NULL, i, all))
		return (FAILURE);
	map_width(i, all);
	fill_2dmap(i, 0, all);
	fill_the_reste_of_the_lines_with_spaces(all);
	if (player_access_empty_space(-1, all))
		return (FAILURE);
	return (SUCCESS);
}

int	check_nl_in_mini_map(char *trimmed, char *trimmed2, int i, t_all *all)
{
	while (all->full_map2[i + 1])
	{
		all->mini_map_height++;
		trimmed = ft_strtrim(all->full_map2[i], " \t");
		trimmed2 = ft_strtrim(all->full_map2[i + 1], " \t");
		(gc_push(trimmed), gc_push(trimmed2));
		if (trimmed[0] == '\0' && trimmed2[0] != '\0')
			return (ft_putstr_fd(RED "Error : nl in the mini map\n" ENDC, 2),
				FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	player_access_empty_space(int i, t_all *all)
{
	size_t	j;

	while (all->two_d_map[++i])
	{
		j = 0;
		while (j < all->mini_map_width)
		{
			if ((all->two_d_map[i][j] == '0' || all->two_d_map[i][j] == 'N'
					|| all->two_d_map[i][j] == 'E'
					|| all->two_d_map[i][j] == 'W'
					|| all->two_d_map[i][j] == 's') && (all->two_d_map[i
					- 1][j] == ' ' || all->two_d_map[i + 1][j] == ' '
					|| all->two_d_map[i][j - 1] == ' ' || all->two_d_map[i][j
					+ 1] == ' ' || all->two_d_map[i - 1][j] == '\t'
					|| all->two_d_map[i + 1][j] == '\t' || all->two_d_map[i][j
					- 1] == '\t' || all->two_d_map[i][j + 1] == '\t'))
				return (ft_putstr_fd(RED "Error : 0 wla Player access\
						empty space\n" ENDC, 2), FAILURE);
			j++;
		}
	}
	return (SUCCESS);
}

int	parsing(t_all *all, int ac, char **av)
{
	all->ac = ac;
	all->av = av;
	all->p_count = 0;
	if (fetch_full_map(all))
		return (ffreeee(0, all->data), _free(), exit(1), FAILURE);
	if (check_full_map_content(all))
		return (ffreeee(0, all->data), _free(), exit(1), FAILURE);
	return (SUCCESS);
}

t_all	*parser(t_data *data, int ac, char **av)
{
	t_all	*all;

	all = ft_calloc(1, sizeof(t_all));
	if (!all)
		return (NULL);
	gc_push(all);
	all->data = data;
	if (ac != 2)
		return (ffreeee(0, data),
			ft_putstr_fd(RED "Error : bad arguments\n" ENDC, 2), _free(),
			exit(1), NULL);
	parsing(all, ac, av);
	return (all);
}
