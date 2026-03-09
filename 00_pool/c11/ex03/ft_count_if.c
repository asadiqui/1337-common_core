/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:07:10 by asadiqui          #+#    #+#             */
/*   Updated: 2023/08/01 18:07:11 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}
/*
int has_a(char *str){if (*str == 'A') return 1; return 0;}
#include <stdio.h>
#include <stdlib.h>
int main () {char *str[] = {"H", "A", "A"};
printf("%d\n", ft_count_if(str, 3, has_a));}*/
