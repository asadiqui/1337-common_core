/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:57:59 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/09 17:12:17 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sml_srt(t_stack **a, t_stack *mdl, t_stack *btm, int size)
{
	if (size == 3 && !(btm->data > mdl->data && btm->data > (*a)->data))
	{
		if ((*a)->data > mdl->data && (*a)->data > btm->data)
		{
			if (mdl->data > btm->data)
			{
				swap("sa", a);
				rrotate("rra", a);
			}
			else
				rotate("ra", a);
		}
		else if (mdl->data > (*a)->data && mdl->data > btm->data)
		{
			if ((*a)->data > btm->data)
				rrotate("rra", a);
			else
			{
				swap("sa", a);
				rotate("ra", a);
			}
		}
	}
	else
		swap("sa", a);
}

void	set_posrot(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	set_position(*a, *b);
	set_rotindex(*a, *size_a);
	set_rotindex(*b, *size_b);
}

void	rotate_both(t_stack **from, t_stack **to, t_stack *move, t_stack *trgt)
{
	int		size_from;
	int		size_to;
	int		min;

	min = move->rot;
	if (trgt->rot < move->rot)
		min = trgt->rot;
	size_from = stack_size(*from);
	size_to = stack_size(*to);
	if (move->pos <= size_from / 2 && trgt->pos <= size_to / 2)
		while (min--)
			rotate("rr", from, to);
	else if (move->pos > size_from / 2 && trgt->pos > size_to / 2)
		while (min--)
			rrotate("rrr", from, to);
}

static void	final_rotation(t_stack **a, int size_a)
{
	t_stack	*current;
	t_stack	*min_value;

	set_position(*a, NULL);
	set_rotindex(*a, size_a);
	min_value = *a;
	current = (*a)->next;
	while (current)
	{
		if (current->data < min_value->data)
			min_value = current;
		current = current->next;
	}
	if (min_value->pos <= size_a / 2)
		while ((*a)->data != min_value->data)
			rotate("ra", a);
	else
		while ((*a)->data != min_value->data)
			rrotate("rra", a);
}

void	sorting_algo(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	int		initial_push;

	initial_push = 2;
	while (initial_push-- && *size_a > 3)
	{
		push(a, b, size_a, size_b);
		ft_putstr("pb\n");
	}
	push_to_b(a, b, size_a, size_b);
	if (!is_sorted(*a))
		sml_srt(a, (*a)->next, (*a)->next->next, *size_a);
	if (*b)
	{
		pushback_to_a(b, a, size_b, size_a);
		final_rotation(a, *size_a);
	}
}
