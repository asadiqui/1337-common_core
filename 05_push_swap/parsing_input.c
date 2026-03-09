/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:13:57 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/15 23:41:59 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skipws(char **string, int mode, t_stack **a)
{
	while ((9 <= **string && **string <= 13) || **string == 32)
		(*string)++;
	if (mode == 2)
	{
		if (**string == '\0')
		{
			write(2, "Error\n", 6);
			free_stack(a);
			return (-1);
		}
	}
	return (0);
}

static long	ft_atoi(char **string)
{
	int		sign;
	long	result;

	sign = 1;
	if (**string == '+' || **string == '-')
	{
		if (**string == '-')
			sign *= -1;
		(*string)++;
	}
	if (**string < '0' || '9' < **string)
		return (LONG_MAX);
	result = 0;
	while ('0' <= **string && **string <= '9')
	{
		result *= 10;
		result += **string - 48;
		if (sign * result < INT_MIN || INT_MAX < sign * result)
			return (LONG_MAX);
		(*string)++;
	}
	if (**string == '+' || **string == '-')
		return (LONG_MAX);
	skipws(string, 1, NULL);
	return (result * sign);
}

static int	addnewnode(t_stack **stack, long data)
{
	t_stack	*current;
	t_stack	*newnode;

	newnode = malloc(sizeof(t_stack));
	if (!newnode)
	{
		write(2, "Error\n", 6);
		free_stack(stack);
		return (-1);
	}
	newnode->data = data;
	newnode->next = NULL;
	if (!*stack)
	{
		newnode->prev = NULL;
		*stack = newnode;
		return (0);
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = newnode;
	newnode->prev = current;
	return (0);
}

static int	check_duplicate(t_stack *stack, long data)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (data == current->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	parsing_input(t_stack **a, int argc, char **argv)
{
	int		argc_index;
	long	data;
	int		stack_size;

	argc_index = 0;
	stack_size = 0;
	while (++argc_index < argc)
	{
		if (skipws(&argv[argc_index], 2, a) == -1)
			break ;
		while (*argv[argc_index])
		{
			data = ft_atoi(&argv[argc_index]);
			if (data > INT_MAX || !check_duplicate(*a, data))
			{
				write(2, "Error\n", 6);
				free_stack(a);
				return (-1);
			}
			if (addnewnode(a, data) < 0)
				return (-1);
			stack_size++;
		}
	}
	return (stack_size);
}
