/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:51:09 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/24 21:51:12 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	array = malloc((max - min) * sizeof(int));
	if (!array)
	{
		*range = 0;
		return (0);
	}
	*range = array;
	i = 0;
	while (i < max - min)
	{
		array[i] = min + i;
		i++;
	}
	return (max - min);
}
/*
#include <stdio.h>
int	main()
{
	int	min = -3;
	int	max = 6;
	int *tab;
	int size = ft_ultimate_range(&tab, min, max);
	int	i = 0;
	while (i < size)
		printf("%d, ", tab[i++]);
	return (0);
}*/