/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:46:06 by asadiqui          #+#    #+#             */
/*   Updated: 2024/08/27 18:51:44 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_usleep(size_t ms, atomic_bool *dead_flag)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < ms && !*dead_flag)
		usleep(500);
	return (0);
}

void	destroy_n_free(char *notice, t_data *program, pthread_mutex_t forks[])
{
	int	i;

	if (notice)
		printf("%s\n", notice);
	pthread_mutex_destroy(&program->write_lock);
	i = 0;
	while (i < program->philo_nbr)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
	free(program->philos);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

static const char	*skip_ws(const char *str)
{
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;
	const char			*s;

	s = skip_ws(str);
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	result = 0;
	while ('0' <= *s && *s <= '9')
	{
		result *= 10;
		if (result > LLONG_MAX)
			return (-1 * (sign == 1));
		result += *s - 48;
		s++;
	}
	return (result * sign);
}
