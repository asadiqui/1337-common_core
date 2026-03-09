/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:46:03 by asadiqui          #+#    #+#             */
/*   Updated: 2024/08/30 15:51:19 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	retreat(atomic_bool dead, pthread_mutex_t **r, pthread_mutex_t **l)
{
	if (!dead)
		return (0);
	if (r)
		pthread_mutex_unlock(*r);
	if (l)
		pthread_mutex_unlock(*l);
	return (1);
}

static int	pick_forks(t_philo **philo)
{
	if (retreat(*((*philo)->dead_flag), NULL, NULL))
		return (1);
	pthread_mutex_lock((*philo)->right_fork);
	print_notice("has taken a fork 🥄", (*philo), (*philo)->id);
	if ((*philo)->philo_nbr == 1)
	{
		pthread_mutex_unlock((*philo)->right_fork);
		ft_usleep((*philo)->time_to_die, (*philo)->dead_flag);
		return (1);
	}
	if (retreat(*((*philo)->dead_flag), &((*philo)->right_fork), NULL))
		return (1);
	if ((*philo)->id % 2 && (*philo)->philo_nbr % 2)
		usleep(500);
	pthread_mutex_lock((*philo)->left_fork);
	print_notice("has taken a fork 🥄", (*philo), (*philo)->id);
	if (retreat(*((*philo)->dead_flag), &((*philo)->right_fork), \
		&((*philo)->left_fork)))
		return (1);
	return (0);
}

static void	eat_routine(t_philo	*philo)
{
	if (pick_forks(&philo))
		return ;
	philo->is_eating = 1;
	print_notice("is eating 😋", philo, philo->id);
	philo->last_meal = get_current_time();
	philo->eating_times++;
	ft_usleep(philo->time_to_eat, philo->dead_flag);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*philo_routine(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	if ((philo->id % 2))
		usleep(500);
	while (!*(philo->dead_flag))
	{
		eat_routine(philo);
		if (*(philo->dead_flag))
			break ;
		print_notice("is sleeping 😴", philo, philo->id);
		ft_usleep(philo->time_to_sleep, philo->dead_flag);
		if (*(philo->dead_flag))
			break ;
		print_notice("is thinking 💡", philo, philo->id);
	}
	return (NULL);
}

void	thread_create(t_data *program, pthread_mutex_t forks[])
{
	pthread_t	monitor_thread;
	int			i;

	if (pthread_create(&monitor_thread, NULL, monitor, program->philos) != 0)
		destroy_n_free("Thread creation error", program, forks);
	i = 0;
	while (i < program->philo_nbr)
	{
		if (pthread_create(&program->philos[i].thread, NULL, philo_routine,
				&program->philos[i]) != 0)
			destroy_n_free("Thread creation error", program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(monitor_thread, NULL) != 0)
		destroy_n_free("Thread join error", program, forks);
	while (i < program->philo_nbr)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destroy_n_free("Thread join error", program, forks);
		i++;
	}
}
