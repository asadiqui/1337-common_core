/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:23:29 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/13 17:33:03 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	is_sorted(t_stack *a)
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

void	set_position(t_stack *a, t_stack *b)
{
	t_stack	*current;
	int		index;
	int		count;

	count = 2;
	current = a;
	while (current && count--)
	{
		index = 0;
		while (current)
		{
			current->pos = index++;
			current = current->next;
		}
		current = b;
	}
}

void	set_rotindex(t_stack *stack, int size)
{
	t_stack	*current;
	int		index;

	if (!stack)
		return ;
	current = stack;
	index = 0;
	while (index < size / 2)
	{
		current->rot = index++;
		current = current->next;
	}
	if (size % 2)
	{
		current->rot = index;
		current = current->next;
	}
	while (index)
	{
		current->rot = index--;
		current = current->next;
	}
}

int	calculate_moves(t_stack *node, t_stack *target, int size_from, int size_to)
{
	int	max;

	max = node->rot;
	if (target->rot > node->rot)
		max = target->rot;
	if ((node->pos <= size_from / 2 && target->pos <= size_to / 2) \
		|| (node->pos >= size_from / 2 && target->pos >= size_to / 2))
		return (max);
	return (node->rot + target->rot);
}
