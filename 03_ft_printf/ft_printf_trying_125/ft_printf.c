/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:25:02 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/26 16:42:01 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initialise_struct(t_strct *vars)
{
	vars->nbr_prints = 0;
}

static const char	*handle_format(t_strct *vars, const char *format)
{
	if (*format == '%')
		vars->nbr_prints += write(1, "%%", 1);
	else if (*format == 'c')
		ft_putchar(vars);
	else if (*format == 's')
		ft_putstr(vars);
	else if (*format == 'p')
		ft_puthexa(vars, 0, 1);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(vars);
	else if (*format == 'u')
		ft_putunsigned(vars);
	else if (*format == 'x')
		ft_puthexa(vars, 0, 0);
	else if (*format == 'X')
		ft_puthexa(vars, 1, 0);
	if (*(format + 1))
		return (format + 1);
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	t_strct	*vars;
	int		nbr_prints;

	nbr_prints = 0;
	vars = malloc(sizeof(t_strct));
	if (!vars)
		return (-1);
	initialise_struct(vars);
	va_start(vars->ap, format);
	while (format && *format)
	{
		if (*format == '%')
			format = handle_format(vars, format + 1);
		else
		{
			nbr_prints += write(1, format, 1);
			format++;
		}
	}
	nbr_prints += vars->nbr_prints;
	va_end(vars->ap);
	free(vars);
	return (nbr_prints);
}
