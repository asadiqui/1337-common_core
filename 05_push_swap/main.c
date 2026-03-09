/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:48:42 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/15 23:44:13 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_putstr(char *str)
{
	while (*str)
		write (1, str++, 1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size_a;
	int		size_b;

	a = NULL;
	b = NULL;
	size_a = parsing_input(&a, argc, argv);
	size_b = 0;
	if (a && !is_sorted(a))
		sorting_algo(&a, &b, &size_a, &size_b);
	if (a)
		free_stack(&a);
	return (0);
}
// requirements:
// 3 <= 3
// 5 <= 12
// 100 < 700
// 500 < 5500
