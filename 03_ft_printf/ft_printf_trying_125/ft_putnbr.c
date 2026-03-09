/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:24:53 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/30 19:12:08 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putnbr(t_strct *vars)
{
	int		nbr;
	int		i;
	int		is_neg;
	char	str[20];

	// str = malloc(sizeof(char) * 20);
	nbr = va_arg(vars->ap, int);
	is_neg = (nbr < 0);
	if (nbr == 0)
		str[0] = '0';
	i = 0;
	while (nbr)
	{
		str[i++] = '0' + ft_abs(nbr % 10);
		nbr /= 10;
	}
	if (is_neg)
		str[i] = '-';
	else if (i > 0)
		i--;
	while (i >= 0)
		vars->nbr_prints += write(1, &str[i--], 1);
	// free(str);
}
