/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:08:39 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/28 19:05:43 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/*##################################*|
|*				HEADERS				*|
|*##################################*/
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>

/*##################################*|
|*				LIBFT				*|
|*##################################*/
size_t	ft_strlen(const char *str);
void	ft_putstr(int fd, char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);

/*##################################*|
|*				SERVER				*|
|*##################################*/
//int	main(void);
//static void	handler(int signum, siginfo_t *info, void *ucontext);

/*##################################*|
|*				CLIENT				*|
|*##################################*/
// int	main(int ac, char **av);
// static void	send_message(pid_t server_id, char *msg);
// static void	handler(int signum);

#endif