/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:05:56 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/28 19:07:35 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signum, siginfo_t *info, void *ucontext)
{
	static pid_t			client_id = 0;
	static unsigned char	c = 0;
	static int				index = 0;

	(void)ucontext;
	if (!client_id)
		client_id = info->si_pid;
	c |= (signum == SIGUSR2);
	if (++index == 8)
	{
		index = 0;
		if (!c)
		{
			kill(client_id, SIGUSR2);
			client_id = 0;
			return ;
		}
		ft_putchar(c);
		c = 0;
		kill(client_id, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_putstr(2, "CAUTION:\tSERVER_TAKES_NO_ARGS\n");
		exit(EXIT_FAILURE);
	}
	ft_putstr(1, "SERVER PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
