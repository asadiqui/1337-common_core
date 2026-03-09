/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:50:55 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/24 21:50:57 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;

	if (min >= max)
		return (0);
	array = malloc((max - min) * sizeof(int));
	if (!array)
		return (0);
	i = 0;
	while (i < max - min)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}
/*
#include <stdio.h>
int	main()
{
	int	min = -3;
	int	max = 6;
	int	*arr = ft_range(min, max);
	int	i = 0;
	while (i < max - min)
		printf("%d, ", arr[i++]);
	return (0);
}*/