/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:17:21 by asadiqui          #+#    #+#             */
/*   Updated: 2024/05/02 15:19:13 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	retrieve_sign(const char **str)
{
	int	sign;

	while ((9 <= **str && **str <= 13) || **str == 32)
		(*str)++;
	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	if (**str < '0' || '9' < **str)
		error_msg();
	return (sign);
}

double	ft_atoi(const char *str)
{
	int			sign;
	long double	result;
	int			comma_reached;

	sign = retrieve_sign(&str);
	result = 0;
	comma_reached = 0;
	while (!comma_reached && '0' <= *str && *str <= '9')
	{
		result = result * 10 + *(str++) - 48;
		if (result > DBL_MAX)
			error_msg();
		if (*str == '.' && str++)
			comma_reached = 1;
	}
	while ('0' <= *str && *str <= '9' && comma_reached)
	{
		result += ((*str - 48) / pow(10, comma_reached++));
		str++;
	}
	if (*str && (*str < '0' || '9' < *str))
		error_msg();
	return (result * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	if (!(*s1) && !(*s2))
		return (0);
	else
	{
		while (*us1 || *us2)
		{
			if (*us1 != *us2)
				return (*us1 - *us2);
			us1++;
			us2++;
		}
	}
	return (0);
}
