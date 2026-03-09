/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_rev_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:03:08 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/13 22:03:12 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		siz;
	int		swap;

	siz = size - 1;
	i = 0;
	swap = 0;
	while (siz > i)
	{
		swap = tab[i];
		tab[i] = tab[siz];
		tab[siz] = swap;
		i++;
		siz--;
	}
}
