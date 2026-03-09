/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:27:30 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/30 19:09:47 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static void	ft_padalign_str(t_strct *vars, char *str)
{
	int	tmpmax;

	if (vars->maxwidth < ft_strlen(str) && vars->point)
		vars->minwidth -= vars->maxwidth;
	else
		vars->minwidth -= ft_strlen(str);
	tmpmax = vars->maxwidth - ft_strlen(str);
	if ((!vars->dash && vars->point) || (!vars->dash && !vars->point))
		while (vars->minwidth-- > 0)
			vars->nbr_prints += write(1, " ", 1);
	if (vars->point)
		while (*str && vars->maxwidth--)
			vars->nbr_prints += write (1, str++, 1);
	else
		while (*str)
			vars->nbr_prints += write (1, str++, 1);
	if (vars->dash && vars->point)
		while (vars->minwidth-- > 0)
			vars->nbr_prints += write(1, " ", 1);
	if (vars->dash && !vars->point)
		while (tmpmax-- > 0)
			vars->nbr_prints += write(1, " ", 1);
}

void	ft_putstr(t_strct *vars)
{
	char	*str;

	str = va_arg(vars->ap, char *);
	if (!str)
	{
		ft_padalign_str(vars, "(null)");
		return ;
	}
	ft_padalign_str(vars, str);
}
