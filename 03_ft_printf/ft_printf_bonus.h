/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:34:33 by asadiqui          #+#    #+#             */
/*   Updated: 2023/12/01 17:49:12 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_strct {
	va_list			ap;
	int				hash;
	int				space;
	int				plus;
	int				width;
	int				nbr_prints;
	unsigned long	nbr;
	int				i;
	char			*str;
	int				not_zero;
}	t_strct;

int		ft_printf(const char *format, ...);
void	ft_putchar(t_strct *vars);
void	ft_putstr(t_strct *vars);
void	ft_putnbr(t_strct *vars);
void	ft_putunsigned(t_strct *vars);
void	ft_puthexa(t_strct *vars, int uc, int address);

#endif