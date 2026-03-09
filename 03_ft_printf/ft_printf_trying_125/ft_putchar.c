/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:24:19 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/26 13:20:36 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(t_strct *vars)
{
	char	c;

	c = va_arg(vars->ap, int);
	vars->nbr_prints += write(1, &c, 1);
}
