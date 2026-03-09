/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:07:56 by asadiqui          #+#    #+#             */
/*   Updated: 2023/08/01 18:07:58 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	swapped;
	int	size;

	size = 0;
	while (tab[size])
		size++;
	while (1)
	{
		i = 0;
		swapped = 0;
		while (i < size - 1)
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(&tab[i], &tab[i + 1]);
				swapped = 1;
			}
			i++;
		}
		if (!swapped)
			break ;
	}
}
