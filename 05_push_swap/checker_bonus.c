/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:55:07 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/15 23:46:32 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	is_sorted(t_stack *a)
{
	t_stack	*current;

	current = a;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

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
	int		a_size;

	a = NULL;
	b = NULL;
	a_size = parsing_input(&a, argc, argv);
	if (a && call_instruction(&a, &b))
	{
		if (a && a_size == stack_size(a) && is_sorted(a))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		if (a)
			free_stack(&a);
		if (b)
			free_stack(&b);
	}
	return (0);
}
