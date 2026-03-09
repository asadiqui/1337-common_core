/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:07:00 by asadiqui          #+#    #+#             */
/*   Updated: 2023/08/01 18:07:01 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	while (*tab)
	{
		if (f(*tab))
			return (1);
		tab++;
	}
	return (0);
}
/*
int has_a(char *str){if (*str == 'A') return 1; return 0;}
#include <stdio.h>
#include <stdlib.h>
int main () {char *str[] = {"H", "A", NULL};
printf("%d\n", ft_any(str, has_a));}*/
