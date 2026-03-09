/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:27:15 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/29 19:38:53 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar(t_strct *vars)
{
	char	c;

	c = va_arg(vars->ap, int);
	while (--vars->minwidth > 0)
		vars->nbr_prints += write(1, " ", 1);
	vars->nbr_prints += write(1, &c, 1);
	while (vars->dash && --vars->maxwidth > 0)
		vars->nbr_prints += write(1, " ", 1);
}
