/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:24:12 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/11 16:47:19 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*return_target1(t_stack *node, t_stack *stack, long smlst_bgr)
{
	t_stack	*target;

	target = stack;
	if (smlst_bgr == LONG_MAX)
	{
		while (stack)
		{
			if (stack->data < target->data)
				target = stack;
			stack = stack->next;
		}
	}
	else
	{
		while (stack)
		{
			if (node->data < stack->data && stack->data <= smlst_bgr)
			{
				target = stack;
				smlst_bgr = stack->data;
			}
			stack = stack->next;
		}
	}
	return (target);
}

static t_stack	*search_smallest_bigger_than(t_stack *node, t_stack *a)
{
	t_stack	*tmp;
	long	smallest_bigger_than;

	tmp = a;
	smallest_bigger_than = LONG_MAX;
	while (tmp)
	{
		if (node->data < tmp->data)
		{
			smallest_bigger_than = tmp->data;
			break ;
		}
		tmp = tmp->next;
	}
	return (return_target1(node, a, smallest_bigger_than));
}

static void	rotate_stack1(t_stack **fm, t_stack **to, t_stack *mv, t_stack *tg)
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
			rotate("rb", fm);
		else
			rrotate("rrb", fm);
		current_from = *fm;
	}
	while (current_to->data != tg->data)
	{
		if (tg->pos <= size_to / 2)
			rotate("ra", to);
		else
			rrotate("rra", to);
		current_to = *to;
	}
}

static void	rotate_to_push1(t_stack **b, t_stack **a, t_stack *mv, t_stack *tg)
{
	rotate_both(b, a, mv, tg);
	rotate_stack1(b, a, mv, tg);
	ft_putstr("pa\n");
}

void	pushback_to_a(t_stack **from, t_stack **to, int *siz_from, int *siz_to)
{
	t_stack	*crnt;
	t_stack	*search;
	t_stack	*node_to_move;
	t_stack	*target;
	int		least_mvs;

	while (*siz_from)
	{
		set_posrot(from, to, siz_from, siz_to);
		crnt = *from;
		least_mvs = INT_MAX;
		while (crnt)
		{
			search = search_smallest_bigger_than(crnt, *to);
			if (calculate_moves(crnt, search, *siz_from, *siz_to) < least_mvs)
			{
				node_to_move = crnt;
				target = search;
				least_mvs = calculate_moves(crnt, search, *siz_from, *siz_to);
			}
			crnt = crnt->next;
		}
		rotate_to_push1(from, to, node_to_move, target);
		push(from, to, siz_from, siz_to);
	}
}
