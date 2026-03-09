/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:45:59 by asadiqui          #+#    #+#             */
/*   Updated: 2024/08/30 15:52:17 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_notice(char *notice, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!*(philo->dead_flag))
		printf("%zu %d %s\n", time, id, notice);
	pthread_mutex_unlock(philo->write_lock);
}

int	check_if_dead(t_philo philos[])
{
	int	i;

	i = 0;
	while (i < philos->philo_nbr)
	{
		if (philos[i].time_to_die <= get_current_time() - philos[i].last_meal
			&& !philos[i].is_eating)
		{
			print_notice("died ☠️", &philos[i], philos[i].id);
			return (*(philos->dead_flag) = true, 1);
		}
		i++;
	}
	return (0);
}

int	check_if_eaten_enough(t_philo philos[])
{
	int	i;
	int	philos_eaten_enough;

	i = 0;
	philos_eaten_enough = 0;
	while (i < philos->philo_nbr)
	{
		if (philos[i].eating_times >= philos[i].max_eating_times)
			philos_eaten_enough++;
		i++;
	}
	if (philos_eaten_enough == philos->philo_nbr)
		return (*(philos->dead_flag) = true, 1);
	return (0);
}

void	*monitor(void *philos_arg)
{
	t_philo	*philos;

	philos = (t_philo *)philos_arg;
	while (1)
	{
		if ((philos->max_eating_times != -1 && \
			check_if_eaten_enough(philos)) || (check_if_dead(philos)))
			break ;
	}
	return (NULL);
}
