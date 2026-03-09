/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 06:10:36 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/15 17:54:26 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/************************************|
|*				HEADERS				*|
|************************************/
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

/************************************|
|*				STRUCT				*|
|************************************/
typedef struct stack
{
	struct stack	*prev;
	long			data;
	int				pos;
	int				rot;
	struct stack	*next;
}	t_stack;

/************************************|
|*			MAIN_FUNCTIONS			*|
|************************************/
//int		main(int argc, char **argv);
void	ft_putstr(char *str);
void	free_stack(t_stack **stack);

/************************************|
|*			PARSING_INPUT			*|
|************************************/
int		parsing_input(t_stack **a, int argc, char **argv);
//static void	skipws(char **string);
//static long	ft_atoi(char **string);
//static int		addnewnode(t_stack **stack, long data);
//static int		check_duplicate(t_stack *stack, long data);

/************************************|
|*			INSTRUCTIONS			*|
|************************************/
//void	print_instruction(char *instruction, int *number_of_stacks);
void	push(t_stack **from, t_stack **to, int *size_from, int *size_to);
void	swap(char *instruction, ...);
void	rotate(char *instruction, ...);
void	rrotate(char *instruction, ...);

/************************************|
|*			AUXILIARY				*|
|************************************/
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *a);
void	set_position(t_stack *a, t_stack *b);
void	set_rotindex(t_stack *stack, int size);
int		calculate_moves(t_stack *node, t_stack *trgt, int siz_frm, int siz_to);

/************************************|
|*			SORTING_ALGO			*|
|************************************/
void	sorting_algo(t_stack **a, t_stack **b, int *size_a, int *size_b);
void	set_posrot(t_stack **a, t_stack **b, int *size_a, int *size_b);
void	rotate_both(t_stack **from, t_stack **to, t_stack *move, t_stack *trgt);
//static void	sml_srt(t_stack **a, t_stack *mdl, t_stack *btm, int size);
//static void	final_rotation(t_stack **a, int size_a);

/************************************|
|*			PUSH_TO_B				*|
|************************************/
void	push_to_b(t_stack **from, t_stack **to, int *size_from, int *size_to);
//void	rotate_to_push0(t_stack **a, t_stack **b, t_stack *move, t_stack *trgt);
//void	rotate_stack0(t_stack **frm, t_stack **to, t_stack *mov, t_stack *trgt);
//static t_stack	*search_biggest_smaller_than(t_stack *node, t_stack *b);
//t_stack	*return_target0(t_stack *node, t_stack *stack, long bgst_smlr_than);

/************************************|
|*			PUSH_BACK_TO_A			*|
|************************************/
void	pushback_to_a(t_stack **from, t_stack **to, int *siz_from, int *siz_to);
//void	rotate_to_push1(t_stack **b, t_stack **a, t_stack *move, t_stack *trgt);
//void	rotate_stack1(t_stack **frm, t_stack **to, t_stack *mov, t_stack *trgt);
//static t_stack	*search_smallest_bigger_than(t_stack *node, t_stack *a);
//t_stack	*return_target1(t_stack *node, t_stack *stack, long smlst_bgr_than);

#endif