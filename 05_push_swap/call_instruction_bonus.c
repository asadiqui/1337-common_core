/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_instruction_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:07:33 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/11 18:55:33 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	execute_instruction(t_stack **a, t_stack **b, char *instruction)
{
	if (!ft_strcmp(instruction, "pa\n"))
		push(b, a);
	else if (!ft_strcmp(instruction, "pb\n"))
		push(a, b);
	else if (!ft_strcmp(instruction, "sa\n"))
		swap("sa", a);
	else if (!ft_strcmp(instruction, "sb\n"))
		swap("sb", b);
	else if (!ft_strcmp(instruction, "ss\n"))
		swap("ss", a, b);
	else if (!ft_strcmp(instruction, "ra\n"))
		rotate("ra", a);
	else if (!ft_strcmp(instruction, "rb\n"))
		rotate("rb", b);
	else if (!ft_strcmp(instruction, "rr\n"))
		rotate("rr", a, b);
	else if (!ft_strcmp(instruction, "rra\n"))
		rrotate("rra", a);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrotate("rrb", b);
	else if (!ft_strcmp(instruction, "rrr\n"))
		rrotate("rrr", a, b);
}

static int	check_error(char *line)
{
	if (!ft_strcmp(line, "pa\n") \
		|| !ft_strcmp(line, "pb\n") \
		|| !ft_strcmp(line, "sa\n") \
		|| !ft_strcmp(line, "sb\n") \
		|| !ft_strcmp(line, "ss\n") \
		|| !ft_strcmp(line, "ra\n") \
		|| !ft_strcmp(line, "rb\n") \
		|| !ft_strcmp(line, "rr\n") \
		|| !ft_strcmp(line, "rra\n") \
		|| !ft_strcmp(line, "rrb\n") \
		|| !ft_strcmp(line, "rrr\n"))
		return (1);
	return (0);
}

int	call_instruction(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (1);
		else if (!check_error(line))
		{
			write(2, "Error\n", 6);
			free(line);
			return (0);
		}
		else
			execute_instruction(a, b, line);
		free(line);
	}
	return (1);
}
