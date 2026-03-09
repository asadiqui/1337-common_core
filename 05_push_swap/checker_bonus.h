/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:55:17 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/15 17:57:04 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

/************************************|
|*				HEADERS				*|
|************************************/
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>

/************************************|
|*				STRUCT				*|
|************************************/
typedef struct stack
{
	struct stack	*prev;
	long			data;
	struct stack	*next;
}	t_stack;

/************************************|
|*			MAIN_FUNCTIONS			*|
|************************************/
//int		main(int argc, char **argv);
void	ft_putstr(char *str);
void	free_stack(t_stack **stack);
//static int		is_sorted(t_stack *a);

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
//static void	print_instruction(char *instruction, int *number_of_stacks);
void	push(t_stack **from, t_stack **to);
void	swap(char *instruction, ...);
void	rotate(char *instruction, ...);
void	rrotate(char *instruction, ...);

/************************************|
|*			GET_NEXT_LINE			*|
|************************************/
char	*get_next_line(int fd);
//static char	*read_from_fd(int fd, char *buff);
//static char	*ft_free(int i, ...);

/************************************|
|*			GNL_UTILS				*|
|************************************/
size_t	ft_strlen(const char *str);
int		ft_strchr(const char *s, int c);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/************************************|
|*			CALL_INSTRUCTIONS		*|
|************************************/
int		call_instruction(t_stack **a, t_stack **b);
//static int		check_error(char *line);
//static void	execute_instruction(t_stack **a, t_stack **b, char *instrctn);
//static int		ft_strcmp(char *s1, char *s2);
int		stack_size(t_stack *stack);

#endif