/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:18:09 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/19 17:04:24 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*******************************|
|			INSTRUCTIONS		|
|*******************************|
| t_stack	**a, **b;			|
| pa:	push(b, a);				|
| pb:	push(a, b);				|
| sa:	swap("sa", a);			|
| sb:	swap("sb", b);			|
| ss:	swap("ss", a, b);		|
| ra:	rotate("ra", a); ←↑		|
| rb:	rotate("rb", b);		|
| rr:	rotate("rr", a, b);		|
| rra:	rrotate("rra", a); →↓	|
| rrb:	rrotate("rrb", b);		|
| rrr:	rrotate("rrr", a, b);	|
|*******************************/

static void	print_instruction(char *instruction, int *number_of_stacks)
{
	int	len;

	len = 0;
	while (instruction[len])
		len++;
	if (number_of_stacks)
	{
		*number_of_stacks = 1;
		if (instruction[len - 1] == 's' || instruction[len - 1] == 'r')
			*number_of_stacks = 2;
	}
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*nodetomove;

	if (!*from)
		return ;
	nodetomove = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	nodetomove->next = *to;
	if (*to)
		(*to)->prev = nodetomove;
	*to = nodetomove;
}

void	swap(char *instruction, ...)
{
	t_stack	*picker;
	va_list	args;
	long	tmp_data;
	int		number_of_stacks;

	print_instruction(instruction, &number_of_stacks);
	va_start(args, instruction);
	while (number_of_stacks--)
	{
		picker = *(va_arg(args, t_stack **));
		if (!picker)
			return ;
		tmp_data = picker->data;
		picker->data = picker->next->data;
		picker->next->data = tmp_data;
	}
	va_end(args);
}

void	rotate(char *instruction, ...)
{
	t_stack	*head_node;
	t_stack	*tail_node;
	t_stack	**picker;
	va_list	args;
	int		number_of_stacks;

	print_instruction(instruction, &number_of_stacks);
	va_start(args, instruction);
	while (number_of_stacks--)
	{
		picker = va_arg(args, t_stack **);
		if (!*picker)
			return ;
		head_node = *picker;
		tail_node = *picker;
		while (tail_node->next)
			tail_node = tail_node->next;
		*picker = (*picker)->next;
		if (*picker)
			(*picker)->prev = NULL;
		tail_node->next = head_node;
		head_node->prev = tail_node;
		head_node->next = NULL;
	}
	va_end(args);
}

void	rrotate(char *instruction, ...)
{
	t_stack	*head_node;
	t_stack	*tail_node;
	t_stack	**picker;
	va_list	args;
	int		number_of_stacks;

	print_instruction(instruction, &number_of_stacks);
	va_start(args, instruction);
	while (number_of_stacks--)
	{
		picker = va_arg(args, t_stack **);
		if (!*picker)
			return ;
		head_node = *picker;
		tail_node = *picker;
		while (tail_node->next)
			tail_node = tail_node->next;
		if (tail_node->prev)
			tail_node->prev->next = NULL;
		head_node->prev = tail_node;
		tail_node->next = head_node;
		tail_node->prev = NULL;
		*picker = (*picker)->prev;
	}
	va_end(args);
}
