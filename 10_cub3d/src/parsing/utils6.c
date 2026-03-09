/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:45:07 by merrahal          #+#    #+#             */
/*   Updated: 2024/11/16 13:44:10 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_parsing.h"

void	map_width(int i, t_all *all)
{
	while (all->full_map2[i])
	{
		if (ft_strlen(all->full_map2[i]) > all->mini_map_width)
			all->mini_map_width = ft_strlen(all->full_map2[i]);
		i++;
	}
}

void	fill_2dmap(int i, int j, t_all *all)
{
	all->two_d_map = ft_calloc((all->mini_map_height + 1), sizeof(char *));
	all->two_d_map[all->mini_map_height] = NULL;
	gc_push(all->two_d_map);
	while (all->full_map2[i])
	{
		all->two_d_map[j] = ft_calloc((all->mini_map_width + 1), sizeof(char));
		gc_push(all->two_d_map[j]);
		ft_strcpy(all->two_d_map[j], all->full_map2[i]);
		i++;
		j++;
	}
}

void	fill_the_reste_of_the_lines_with_spaces(t_all *all)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (all->two_d_map[i])
	{
		j = 0;
		while (j < all->mini_map_width)
		{
			if (all->two_d_map[i][j] == '\0')
				all->two_d_map[i][j] = ' ';
			j++;
		}
		i++;
	}
}
