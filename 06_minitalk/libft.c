/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:49:04 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/28 19:05:57 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(int fd, char *str)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putnbr(int n)
{
	int		i;
	char	str[12];
	int		is_neg;

	is_neg = (n < 0);
	if (n == 0)
		str[0] = '0';
	i = 0;
	while (n)
	{
		if (is_neg)
			n *= -1;
		str[i++] = '0' + (n % 10);
		n /= 10;
	}
	if (is_neg)
		str[i] = '-';
	else if (i > 0)
		i--;
	while (i >= 0)
		write(STDOUT_FILENO, &str[i--], 1);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		if (result > LLONG_MAX)
			return (-1 * (sign == 1));
		result += *str - 48;
		str++;
	}
	return (result * sign);
}
