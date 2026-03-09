/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:27:30 by asadiqui          #+#    #+#             */
/*   Updated: 2023/12/01 16:16:48 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putstr(t_strct *vars)
{
	char	*str;

	str = va_arg(vars->ap, char *);
	if (!str)
	{
		vars->nbr_prints += write (1, "(null)", 6);
		return ;
	}
	while (*str)
		vars->nbr_prints += write (1, str++, 1);
}
