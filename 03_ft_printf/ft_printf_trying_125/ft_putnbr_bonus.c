/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:27:25 by asadiqui          #+#    #+#             */
/*   Updated: 2023/12/01 15:32:21 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	char	str[200];

	// str = malloc(sizeof(char) * 20);
	nbr = va_arg(vars->ap, int);
	is_neg = (nbr < 0);
	i = 0;
	if (nbr == 0)
		str[i++] = '0';
	while (nbr)
	{
		str[i++] = '0' + ft_abs(nbr % 10);
		nbr /= 10;
	}
	vars->maxwidth -= i;
	// if (vars->minwidth && vars->maxwidth && is_neg && vars->dash)
	if (is_neg && vars->zero && vars->maxwidth && !vars->point)
		vars->maxwidth--;
	// if (!is_neg && vars->space && !vars->point)
	// 	vars->maxwidth--;
	if ((vars->space || vars->plus) && !vars->point)
		vars->maxwidth--;
	while ((!vars->dash || (vars->dash && vars->point)) && vars->maxwidth-- > 0)
		str[i++] = '0';
	
	vars->minwidth -= i + is_neg;
	if (is_neg)
		str[i] = '-';
	else if (!is_neg && vars->plus)
	{
		str[i] = '+';
		vars->minwidth--;
		// vars->maxwidth--;
	}
	else if (!is_neg && vars->space)
	{
		str[i] = ' ';
		vars->minwidth--;
		//vars->maxwidth--; // xxx
	}
	else if (i > 0)
		i--;
	while (!(vars->dash && vars->point) && vars->minwidth-- > 0)
		vars->nbr_prints += write(1, " ", 1);
	while (i >= 0)
	 	vars->nbr_prints += write(1, &str[i--], 1);
	if (vars->dash && vars->point)
		while (vars->minwidth-- > 0)
			vars->nbr_prints += write(1, " ", 1);
	if (vars->dash && !vars->point)
	{
		if (is_neg)
			vars->maxwidth--;
		while (vars->maxwidth-- > 0)
			vars->nbr_prints += write(1, " ", 1);
	}
	// free(str);
}
