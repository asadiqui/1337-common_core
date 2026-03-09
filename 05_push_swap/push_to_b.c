/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:24:06 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/11 16:45:05 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*return_target0(t_stack *node, t_stack *stack, long bgst_smlr)
{
	t_stack	*target;

	target = stack;
	if (bgst_smlr == LONG_MAX)
	{
		while (stack)
		{
			if (stack->data > target->data)
				target = stack;
			stack = stack->next;
		}
	}
	else
	{
		while (stack)
		{
			if (node->data > stack->data && stack->data >= bgst_smlr)
			{
				target = stack;
				bgst_smlr = stack->data;
			}
			stack = stack->next;
		}
	}
	return (target);
}

static t_stack	*search_biggest_smaller_than(t_stack *node, t_stack *b)
{
	t_stack	*tmp;
	long	biggest_smaller_than;

	tmp = b;
	biggest_smaller_than = LONG_MAX;
	while (tmp)
	{
		if (node->data > tmp->data)
		{
			biggest_smaller_than = tmp->data;
			break ;
		}
		tmp = tmp->next;
	}
	return (return_target0(node, b, biggest_smaller_than));
}

static void	rotate_stack0(t_stack **fm, t_stack **to, t_stack *mv, t_stack *tg)
{
	t_stack	*current_from;
	t_stack	*current_to;
	int		size_from;
	int		size_to;

	size_from = stack_size(*fm);
	size_to = stack_size(*to);
	current_from = *fm;
	current_to = *to;
	while (current_from->data != mv->data)
	{
		if (mv->pos <= size_from / 2)
			rotate("ra", fm);
		else
			rrotate("rra", fm);
		current_from = *fm;
	}
	while (current_to->data != tg->data)
	{
		if (tg->pos <= size_to / 2)
			rotate("rb", to);
		else
			rrotate("rrb", to);
		current_to = *to;
	}
}

static void	rotate_to_push0(t_stack **a, t_stack **b, t_stack *mv, t_stack *tg)
{
	rotate_both(a, b, mv, tg);
	rotate_stack0(a, b, mv, tg);
	ft_putstr("pb\n");
}

void	push_to_b(t_stack **from, t_stack **to, int *size_from, int *size_to)
{
	t_stack	*crnt;
	t_stack	*search;
	t_stack	*node_to_move;
	t_stack	*target;
	int		least_mvs;

	while (*size_from > 3)
	{
		set_posrot(from, to, size_from, size_to);
		crnt = *from;
		least_mvs = INT_MAX;
		while (crnt)
		{
			search = search_biggest_smaller_than(crnt, *to);
			if (calculate_moves(crnt, search, *size_from, *size_to) < least_mvs)
			{
				node_to_move = crnt;
				target = search;
				least_mvs = calculate_moves(crnt, search, *size_from, *size_to);
			}
			crnt = crnt->next;
		}
		rotate_to_push0(from, to, node_to_move, target);
		push(from, to, size_from, size_to);
	}
}
