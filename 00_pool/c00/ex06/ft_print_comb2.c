/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:05:14 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/13 16:32:28 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	n;
	int	m;

	n = 0;
	while (n <= 98)
	{
		m = n + 1;
		while (m <= 99)
		{
			ft_putchar(n / 10 + 48);
			ft_putchar(n % 10 + 48);
			ft_putchar(' ');
			ft_putchar(m / 10 + 48);
			ft_putchar(m % 10 + 48);
			if (n != 98)
			{
				write(1, ", ", 2);
			}
			m++;
		}
		n++;
	}
}
