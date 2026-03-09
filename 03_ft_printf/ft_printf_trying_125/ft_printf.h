/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:13:14 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/27 14:30:38 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_strct {
	va_list	ap;
	int		nbr_prints;
}	t_strct;

int		ft_printf(const char *format, ...);
void	ft_putchar(t_strct *vars);
void	ft_putstr(t_strct *vars);
void	ft_putnbr(t_strct *vars);
void	ft_putunsigned(t_strct *vars);
void	ft_puthexa(t_strct *vars, int uc, int address);

#endif