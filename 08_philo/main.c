/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:45:55 by asadiqui          #+#    #+#             */
/*   Updated: 2024/08/29 09:35:48 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_arg_content(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	check_valid_args(char **av)
{
	if (ft_atoi(av[1]) > 200 || ft_atoi(av[1]) <= 0
		|| check_arg_content(av[1]) == 1)
		return (write(2, "Invalid philosophers number\n", 28), 1);
	if (ft_atoi(av[2]) <= 0 || check_arg_content(av[2]) == 1)
		return (write(2, "Invalid time_to_die\n", 20), 1);
	if (ft_atoi(av[3]) <= 0 || check_arg_content(av[3]) == 1)
		return (write(2, "Invalid time_to_eat\n", 20), 1);
	if (ft_atoi(av[4]) <= 0 || check_arg_content(av[4]) == 1)
		return (write(2, "Invalid time_to_sleep\n", 22), 1);
	if (av[5] && (ft_atoi(av[5]) < 0 || check_arg_content(av[5]) == 1))
		return (write(2, "Invalid max_eating_times\n", 25), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data			program;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				philo_nbr;

	if (ac != 5 && ac != 6)
		return (write(2, "Wrong argument count\n", 21), 1);
	if (check_valid_args(av) == 1)
		return (1);
	philo_nbr = ft_atoi(av[1]);
	philos = malloc(sizeof(t_philo) * philo_nbr);
	forks = malloc(sizeof(pthread_mutex_t) * philo_nbr);
	if (!philos || !forks)
		return (write(2, "Malloc problem\n", 15), 1);
	init_program(&program, philos, philo_nbr);
	init_fork_mutexes(forks, philo_nbr);
	init_philo_structs(philos, &program, forks, av);
	thread_create(&program, forks);
	destroy_n_free(NULL, &program, forks);
	return (0);
}
