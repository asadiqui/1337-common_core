/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:25:09 by asadiqui          #+#    #+#             */
/*   Updated: 2023/12/02 14:20:12 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	initialise_struct(t_strct *vars, int all)
{
	vars->hash = 0;
	vars->space = 0;
	vars->plus = 0;
	vars->nbr = 0;
	vars->i = 0;
	vars->str = NULL;
	vars->not_zero = 0;
	if (all)
		vars->nbr_prints = 0;
}

static void	pick_format(t_strct *vars, char f)
{
	if (f == '%')
		vars->nbr_prints += write(1, "%%", 1);
	else if (f == 'c')
		ft_putchar(vars);
	else if (f == 's')
		ft_putstr(vars);
	else if (f == 'p')
		ft_puthexa(vars, 0, 1);
	else if (f == 'd' || f == 'i')
		ft_putnbr(vars);
	else if (f == 'u')
		ft_putunsigned(vars);
	else if (f == 'x')
		ft_puthexa(vars, 0, 0);
	else if (f == 'X')
		ft_puthexa(vars, 1, 0);
}

static const char	*handle_format(t_strct *vars, const char *format)
{
	while (*format == '#' || *format == ' ' || *format == '+')
	{
		if (*format == '#')
			vars->hash = 1;
		else if (*format == ' ')
			vars->space = 1;
		else if (*format == '+')
			vars->plus = 1;
		format++;
	}
	pick_format(vars, *format);
	initialise_struct(vars, 0);
	return (format + 1);
}

int	ft_printf(const char *format, ...)
{
	t_strct	*vars;
	int		nbr_prints;

	nbr_prints = 0;
	vars = malloc(sizeof(t_strct));
	if (!vars)
		return (-1);
	initialise_struct(vars, 1);
	va_start(vars->ap, format);
	while (*format)
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
