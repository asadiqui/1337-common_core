/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:15:57 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/30 19:12:45 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putunsigned(t_strct *vars)
{
	unsigned int	nbr;
	int				i;
	char			str[20];

	// str = malloc(sizeof(char) * 20);
	nbr = va_arg(vars->ap, unsigned int);
	if (nbr == 0)
		str[0] = '0';
	i = 0;
	while (nbr)
	{
		str[i++] = '0' + ft_abs(nbr % 10);
		nbr /= 10;
	}
	if (i > 0)
		i--;
	while (i >= 0)
		vars->nbr_prints += write(1, &str[i--], 1);
	// free(str);
}
