/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:27:21 by asadiqui          #+#    #+#             */
/*   Updated: 2023/12/01 18:15:06 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	putstr_hexa(t_strct *vars)
{
	while (vars->i >= 0)
		vars->nbr_prints += write(1, &vars->str[vars->i--], 1);
	free(vars->str);
}

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
	vars->nbr = fetch_nbr(vars, address);
	vars->not_zero = 0;
	if (vars->nbr)
		vars->not_zero = 1;
	vars->str = malloc(sizeof(char) * 20);
	vars->i = -1;
	if (vars->nbr == 0)
		vars->str[++vars->i] = '0';
	while (vars->nbr)
	{
		if (!uc)
			vars->str[++vars->i] = "0123456789abcdef"[vars->nbr % 16];
		else
			vars->str[++vars->i] = "0123456789ABCDEF"[vars->nbr % 16];
		vars->nbr /= 16;
	}
	if (address || (vars->hash && vars->not_zero == 1))
	{
		if (!uc)
			vars->str[++vars->i] = 'x';
		else
			vars->str[++vars->i] = 'X';
		vars->str[++vars->i] = '0';
	}
	putstr_hexa(vars);
}
