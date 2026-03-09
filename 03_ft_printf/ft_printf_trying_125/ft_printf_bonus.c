/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:25:09 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/30 17:55:26 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	initialise_struct(t_strct *vars, int all)
{
	vars->dash = 0;
	vars->zero = 0;
	vars->point = 0;
	vars->hash = 0;
	vars->space = 0;
	vars->plus = 0;
	vars->minwidth= 0;
	vars->maxwidth = 0;
	if (all)
		vars->nbr_prints = 0;
}

static const char	*handle_format(t_strct *vars, const char *format)
{
	while (*format != 'c' && *format != 's' && *format != 'p' \
		&& *format != 'd' && *format != 'i' && *format != 'u' \
		&& *format != 'x' && *format != 'X' && *format != '%')
	{
		if (*format == '-')
			vars->dash = 1;
		else if (*format == '0')
			vars->zero = 1;
		else if (*format == '.')
			vars->point = 1;
		else if (*format == '#')
			vars->hash = 1;
		else if (*format == ' ')
			vars->space = 1;
		else if (*format == '+')
			vars->plus = 1;
		else if (48 <= *format && *format <= 57)
		{
			while (48 <= *format && *format <= 57)
			{
				if (vars->dash || vars->point || vars->zero)
				{
					// if (vars->dash && vars->point)
					// {
					// 	vars->minwidth = vars->maxwidth;
					// 	vars->maxwidth = 0;
					// }
					vars->maxwidth *= 10;
					vars->maxwidth += *format - 48;
				}
				else if (!vars->dash && !vars->point && !vars->zero)
				{
					vars->minwidth *= 10;
					vars->minwidth += *format - 48;
				}
				format++;
				if (*format == '.' && !vars->minwidth)
				{
					vars->point = -1;
					vars->minwidth = vars->maxwidth;
				 	vars->maxwidth = 0;
					format++;
					while (48 <= *format && *format <= 57)
					{
						vars->maxwidth *= 10;
						vars->maxwidth += *format - 48;
						format++;
					}
				}
			}
			format--;
		}
		format++;
	}
	// if (*(format--) == '.' && !vars->minwidth)
	// // if (vars->dash && vars->point && !vars->minwidth)
	// {
	// 	vars->minwidth = vars->maxwidth;
	// 	vars->maxwidth = 0;
	// 	// format++;
	// // }
	// printf("\n%d;%d;%d\n", vars->minwidth,vars->maxwidth,vars->point);
	if (*format == '%')
	{
		vars->nbr_prints += write(1, "%%", 1);
		while (--vars->maxwidth > 0)
			vars->nbr_prints += write(1, " ", 1);
	}
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
	initialise_struct(vars, 0);
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
	initialise_struct(vars, 1);
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
