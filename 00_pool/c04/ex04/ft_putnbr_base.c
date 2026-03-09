/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:19:37 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/23 14:19:41 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	nb;

	len = 0;
	while (base[len])
		len++;
	if (len <= 1)
		return ;
	if (!valid(base))
		return ;
	nb = nbr;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb < len)
		ft_putchar(base[nb % len]);
	else
	{
		ft_putnbr_base(nb / len, base);
		ft_putnbr_base(nb % len, base);
	}
}
/*
int main()
{
	ft_putnbr_base(2147483647, "01");
	write(1,"\n", 1);
	ft_putnbr_base(-2147483648, "01");
	write(1,"\n", 1);
}*/