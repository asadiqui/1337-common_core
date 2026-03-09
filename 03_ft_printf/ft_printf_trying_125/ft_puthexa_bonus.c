/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:27:21 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/29 23:38:58 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	int				not_zero;

	not_zero = 0;
	nbr = fetch_nbr(vars, address);
	if (nbr)
		not_zero = 1;
	i = 0;
	if (nbr == 0)
		str[i++] = '0';
	while (nbr)
	{
		if (!uc)
			str[i++] = "0123456789abcdef"[nbr % 16];
		else
			str[i++] = "0123456789ABCDEF"[nbr % 16];
		nbr /= 16;
	}
	if (address || (vars->hash && not_zero == 1))
	{
		if (!uc)
			str[i++] = 'x';
		else
			str[i++] = 'X';
		str[i++] = '0';
	}
	vars->maxwidth -= i;
	while (!vars->dash && vars->maxwidth-- > 0)
		str[i++] = '0';
	vars->minwidth -= i;
	if (i > 0)
		i--;
	while (vars->minwidth-- > 0)
		vars->nbr_prints += write(1, " ", 1);
	while (i >= 0)
	 	vars->nbr_prints += write(1, &str[i--], 1);
	while (vars->dash && vars->maxwidth-- > 0)
		vars->nbr_prints += write(1, " ", 1);
}
