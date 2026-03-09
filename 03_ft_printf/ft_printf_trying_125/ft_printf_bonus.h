/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:34:33 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/30 14:52:11 by asadiqui         ###   ########.fr       */
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
	va_list	ap;
	int		dash;
	int		zero;
	int		point;
	int		hash;
	int		space;
	int		plus;
	int		minwidth;
	int		maxwidth;
	int		nbr_prints;
}	t_strct;

int		ft_printf(const char *format, ...);
void	ft_putchar(t_strct *vars);
void	ft_putstr(t_strct *vars);
void	ft_putnbr(t_strct *vars);
void	ft_putunsigned(t_strct *vars);
void	ft_puthexa(t_strct *vars, int uc, int address);

#endif