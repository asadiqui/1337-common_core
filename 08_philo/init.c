/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:45:52 by asadiqui          #+#    #+#             */
/*   Updated: 2024/08/25 20:56:34 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	asymetric_pick_order(t_philo *philo)
{
	pthread_mutex_t	*tmp_ptr;

	tmp_ptr = philo->right_fork;
	philo->right_fork = philo->left_fork;
	philo->left_fork = tmp_ptr;
}

void	init_philo_structs(t_philo philos[], t_data *program,
	pthread_mutex_t forks[], char **av)
{
	int				i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].philo_nbr = ft_atoi(av[1]);
		philos[i].right_fork = &forks[i];
		philos[i].left_fork = &forks[(i + 1) % program->philo_nbr];
		if (philos[i].id % 2)
			asymetric_pick_order(&philos[i]);
		philos[i].start_time = program->start_time;
		philos[i].time_to_die = ft_atoi(av[2]);
		philos[i].time_to_eat = ft_atoi(av[3]);
		philos[i].time_to_sleep = ft_atoi(av[4]);
		if (av[5])
			philos[i].max_eating_times = ft_atoi(av[5]);
		else
			philos[i].max_eating_times = -1;
		philos[i].eating_times = 0;
		philos[i].is_eating = 0;
		philos[i].last_meal = get_current_time();
		philos[i].dead_flag = &program->dead_flag;
		philos[i].write_lock = &program->write_lock;
	}
}

void	init_fork_mutexes(pthread_mutex_t forks[], int philo_nbr)
{
	int	i;

	i = 0;
	while (i < philo_nbr)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_program(t_data *program, t_philo philos[], int philo_nbr)
{
	program->start_time = get_current_time();
	program->philos = philos;
	program->philo_nbr = philo_nbr;
	program->dead_flag = false;
	pthread_mutex_init(&program->write_lock, NULL);
}
