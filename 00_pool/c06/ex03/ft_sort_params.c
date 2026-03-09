/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:55:31 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/23 16:55:33 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_param(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			write (1, &av[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < ac - 1)
	{
		j = 1;
		while (j < (ac - 1))
		{
			if (ft_strcmp(av[j], av[j + 1]) > 0)
			{
				tmp = av[j];
				av[j] = av[j + 1];
				av[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	print_param(ac, av);
	return (0);
}
