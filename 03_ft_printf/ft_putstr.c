/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:24:55 by asadiqui          #+#    #+#             */
/*   Updated: 2023/12/01 16:16:51 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
