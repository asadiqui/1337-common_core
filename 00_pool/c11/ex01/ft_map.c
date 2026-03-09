/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:06:49 by asadiqui          #+#    #+#             */
/*   Updated: 2023/08/01 18:06:50 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*array;
	int	i;

	array = malloc(length * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < length)
	{
		array[i] = f(tab[i]);
		i++;
	}
	return (array);
}
/*
#include <unistd.h>
#include <stdio.h>
void	ft_putchar(char c) {write(1, &c, 1);}
int	ft_nbr(int nb) { return (-nb); }
int main()
{	int	tab[] = {550, 17, 60, 90, 730, -85};
	int length = sizeof(tab) / sizeof(int);
	int *array = ft_map(tab, length, ft_nbr);
	int	i = 0;
	while (i < length) { printf("%d, ", array[i++]);} }*/
