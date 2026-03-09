/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:48:59 by asadiqui          #+#    #+#             */
/*   Updated: 2024/08/30 15:50:26 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/*##########################|
|			HEADERS			|
|##########################*/

# include <pthread.h>
# include <stdatomic.h>
# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>

/*##########################|
|			MACROS			|
|##########################*/

# define MAX_PHILOS 200

/*##########################|
|			STRUCTS			|
|##########################*/

typedef struct s_philo
{
	int				id;
	int				philo_nbr;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	size_t			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				max_eating_times;
	atomic_int		eating_times;
	atomic_int		is_eating;
	atomic_size_t	last_meal;
	atomic_bool		*dead_flag;
	pthread_mutex_t	*write_lock;
}	t_philo;

typedef struct s_data
{
	size_t			start_time;
	t_philo			*philos;
	int				philo_nbr;
	atomic_bool		dead_flag;
	pthread_mutex_t	write_lock;
}	t_data;

/*##########################|
|			MAIN			|
|##########################*/

// static int	check_valid_args(char **av);
// static int	check_arg_content(char *arg);

/*##########################|
|			INIT			|
|##########################*/

void	init_program(t_data *program, t_philo philos[], int philo_nbr);
void	init_fork_mutexes(pthread_mutex_t forks[], int philo_nbr);
void	init_philo_structs(t_philo philos[], t_data *program, \
	pthread_mutex_t forks[], char **av);
// static void	last_philo_to_pick_left_fork_first(t_philo *philo, int nbr);

/*##########################|
|			THREADS			|
|##########################*/
void	thread_create(t_data *program, pthread_mutex_t forks[]);
void	*philo_routine(void *philo_arg);
// static void	eat_routine(t_philo	*philo);
// static int	pick_forks(t_philo **philo);
// static int	retreat(atomic_bool dead, mutex_t **r, mutex_t **l);

/*##########################|
|			MONITOR			|
|##########################*/
void	*monitor(void *philos_arg);
int		check_if_eaten_enough(t_philo philos[]);
int		check_if_dead(t_philo philos[]);
void	print_notice(char *notice, t_philo *philo, int id);

/*##########################|
|			UTILS			|
|##########################*/

void	destroy_n_free(char *notice, t_data *program, pthread_mutex_t forks[]);
size_t	get_current_time(void);
int		ft_atoi(const char *str);
int		ft_usleep(size_t ms, atomic_bool *dead_flag);
// static const char	*skip_ws(const char *str);

#endif