/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:24:33 by asadiqui          #+#    #+#             */
/*   Updated: 2023/08/01 16:24:35 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);

int	calcul(int a, char op, int b)
{
	int	result;
	int	(*ops[5])(int, int);

	ops[0] = ft_add;
	ops[1] = ft_sub;
	ops[2] = ft_mul;
	ops[3] = ft_div;
	ops[4] = ft_mod;
	result = 0;
	if (op == '+')
		result = ops[0](a, b);
	else if (op == '-')
		result = ops[1](a, b);
	else if (op == '*')
		result = ops[2](a, b);
	else if (op == '/')
		result = ops[3](a, b);
	else if (op == '%')
		result = ops[4](a, b);
	return (result);
}

int	main(int ac, char **av)
{
	int		a;
	char	op;
	int		b;

	a = ft_atoi(av[1]);
	op = av[2][0];
	b = ft_atoi(av[3]);
	if (ac == 4)
	{
		if (!(op == '+' || op == '-'
				|| op == '/' || op == '%' || op == '*'))
			write (1, "0", 1);
		else if (op == '/' && b == 0)
			write (1, "Stop : division by zero", 23);
		else if (op == '%' && b == 0)
			write (1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(calcul(a, op, b));
		write(1, "\n", 1);
	}
	return (0);
}
