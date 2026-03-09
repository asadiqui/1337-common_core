/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:33:55 by kait-baa          #+#    #+#             */
/*   Updated: 2024/06/12 22:14:32 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sigint_handler(int signum)
{
	(void)signum;
	write(1, "\n", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	set_exit_status(130);
}

void	sigint_handler_nl(int signum)
{
	(void)signum;
	write(1, "\n", STDOUT_FILENO);
	set_exit_status(130);
}

void	sigint_handler_exit(int signum)
{
	(void)signum;
	set_exit_status(130);
}

void	eof_handler(void)
{
	printf("exit\n");
	free_garbage(&g_global.garbage_list);
	exit(EXIT_SUCCESS);
}
