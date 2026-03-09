/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:24:27 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/27 22:04:03 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long	fetch_nbr(t_strct *vars, int address)
{
	unsigned long	nbr;

	if (address)
		nbr = va_arg(vars->ap, unsigned long);
	else
		nbr = va_arg(vars->ap, unsigned int);
	return (nbr);
}

void	ft_puthexa(t_strct *vars, int uc, int address)
{
	unsigned long	nbr;
	int				i;
	char			str[20];

	nbr = fetch_nbr(vars, address);
	i = -1;
	if (nbr == 0)
		str[++i] = '0';
	while (nbr)
	{
		if (!uc)
			str[++i] = "0123456789abcdef"[nbr % 16];
		else
			str[++i] = "0123456789ABCDEF"[nbr % 16];
		nbr /= 16;
	}
	if (address)
	{
		str[++i] = 'x';
		str[++i] = '0';
	}
	while (i >= 0)
		vars->nbr_prints += write(1, &str[i--], 1);
}
