/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:07:35 by asadiqui          #+#    #+#             */
/*   Updated: 2023/08/01 18:07:37 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*int f(int a, int b) {return a-b;}*/
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ascend;
	int	descend;

	ascend = 0;
	descend = 0;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			ascend = 1;
		else if (f(tab[i], tab[i + 1]) > 0)
			descend = 1;
		i++;
	}
	if (ascend && descend)
		return (0);
	return (1);
}
/*
#include <stdio.h>
int main()
{	int tab[] = {5,2,0};
	int length = sizeof(tab) / sizeof(int);
	printf("%d\n", ft_is_sort(tab, length, f));}*/
