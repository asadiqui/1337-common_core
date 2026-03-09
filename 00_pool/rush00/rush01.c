/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:11:30 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/16 13:11:33 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print(int x, int y, int i, int j)
{
	if ((i == 1 && j == 1)
		|| ((i == x && j == y) && (x != 1 && y != 1)))
		ft_putchar('/');
	else if ((i == x && j == 1) || (i == 1 && j == y))
	{
		ft_putchar('\\');
	}
	else if ((j == 1 || j == y) || (i == 1 || i == x))
	{
		ft_putchar('*');
	}
	else
		ft_putchar(' ');
}

void	rush(x, y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (x <= 0 || y <= 0)
		write(1, "Width or length cannot be <= 0\n", 31);
	while (j <= y && x > 0 && y > 0)
	{
		while (i <= x)
		{
			print(x, y, i, j);
			i++;
		}
		ft_putchar('\n');
		i = 1 ;
		j++;
	}
}
