/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:33:35 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/30 18:16:23 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signum)
{
	static size_t	sent = 0;

	if (signum == SIGUSR1)
		sent++;
	else if (signum == SIGUSR2)
	{
		ft_putstr(1, "PROCESS RECIEVED\t\t: ");
		ft_putnbr(sent);
		ft_putstr(1, " byte(s)\n");
		exit(EXIT_SUCCESS);
	}
}

static void	send_message(pid_t server_id, char *msg)
{
	char	c;
	int		index;

	while (*msg)
	{
		index = 8;
		c = *msg++;
		while (index--)
		{
			if ((c >> index) & 1)
				kill(server_id, SIGUSR2);
			else
				kill(server_id, SIGUSR1);
			usleep(1000);
		}
	}
	index = 8;
	while (index--)
	{
		kill(server_id, SIGUSR1);
		usleep(1000);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3 || !ft_strlen(av[2]))
	{
		ft_putstr(2, "CAUTION:\tUSE ./client PID_SERVER STRING_TO_PASS\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(av[1]) < 0 || kill(ft_atoi(av[1]), 0) == -1)
	{
		if (errno == ESRCH)
			ft_putstr(2, "CAUTION:\tNO_SUCH_PROCESS\n");
		else if (errno == EPERM)
			ft_putstr(2, "CAUTION:\tOPERATION_NOT_PERMITTED\n");
		else
			ft_putstr(2, "CAUTION:\tINVALID_PROCESS_ID\n");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_putstr(1, "CONNECTION ESTABLISHED TO\t: ");
	ft_putnbr(ft_atoi(av[1]));
	ft_putstr(1, "\n");
	send_message(ft_atoi(av[1]), av[2]);
	while (1)
		pause();
	return (0);
}
