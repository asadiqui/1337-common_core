/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:42:28 by merrahal          #+#    #+#             */
/*   Updated: 2024/11/17 16:19:09 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_parsing.h"

int	has_more_than_six_lines(t_all *all)
{
	int		i;
	int		j;
	int		k;
	char	*trimmed;

	i = 0;
	j = 0;
	k = 0;
	while (all->full_map[i])
	{
		trimmed = ft_strtrim(all->full_map[i], " \t");
		if (trimmed[0] != '\0')
		{
			j++;
			all->full_map[k++] = trimmed;
		}
		gc_push(trimmed);
		i++;
	}
	all->full_map[k] = NULL;
	return (j > 6);
}

int	isnt_valid(char *splitted, t_texture_pars *tmp)
{
	if (strncmp(splitted, "NO", 3) == 0)
		tmp->no_count++;
	else if (strncmp(splitted, "SO", 3) == 0)
		tmp->so_count++;
	else if (strncmp(splitted, "WE", 3) == 0)
		tmp->we_count++;
	else if (strncmp(splitted, "EA", 3) == 0)
		tmp->ea_count++;
	else if (strncmp(splitted, "F", 2) == 0)
		tmp->f_count++;
	else if (strncmp(splitted, "C", 2) == 0)
		tmp->c_count++;
	else
		return (FAILURE);
	return (SUCCESS);
}

int	parse_textures_colors(t_all *all)
{
	int				i;
	t_texture_pars	tmp;
	char			**splitted;

	i = 0;
	ft_bzero(&tmp, sizeof(t_texture_pars));
	while (all->full_map[i] && i < 6)
	{
		splitted = ft_split_multi(all->full_map[i], " \t");
		if (isnt_valid(splitted[0], &tmp) == FAILURE)
			return (ft_putstr_fd(RED "Error: in textures \
				or collors\n" ENDC, 2), FAILURE);
		i++;
	}
	if (tmp.f_count == 0 || tmp.c_count == 0 || tmp.no_count == 0
		|| tmp.so_count == 0 || tmp.we_count == 0 || tmp.ea_count == 0
		|| tmp.no_count > 1 || tmp.so_count > 1 || tmp.we_count > 1
		|| tmp.ea_count > 1 || tmp.f_count > 1 || tmp.c_count > 1)
		return (ft_putstr_fd(RED "Error: dupplicates\n" ENDC, 2), FAILURE);
	return (SUCCESS);
}

int	has_only_ones(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	is_player(t_all *all, char *line, int i)
{
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		all->p_count++;
	if ((line[i] == '0' && line[i + 1] == ' ') || (line[i] == '0' && line[i
				+ 1] == '\t') || (line[i] == '0' && line[i - 1] == ' ')
		|| (line[i] == '0' && line[i - 1] == '\t'))
	{
		return (ft_putstr_fd(RED "Error: invalid map \
			0 hdaha space\n" ENDC, 2), FAILURE);
	}
	return (SUCCESS);
}
