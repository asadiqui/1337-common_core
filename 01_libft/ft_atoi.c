/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:47:48 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/18 14:01:57 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// int main()
// {
// 	// LLONG_MAX = 9223372036854775807;
// 	// ULLONG_MAX = 18446744073709551615;
// 	const char	str[] = "1844674407354645709551616";
// 	int	num1 = ft_atoi(str);
// 	int	num2 = atoi(str);
// 	printf("ft_atoi: %d\n", num1);
// 	printf("   atoi: %d\n", num2);
// 	return (0);
// }