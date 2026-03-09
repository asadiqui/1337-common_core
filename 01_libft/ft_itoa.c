/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:23:35 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/10 20:58:58 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[len] = 0 + 48;
	while (n > 0)
	{
		str[len--] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

// #include <stdio.h>
// #include <limits.h>
// int main()
// {
// 	int n = INT_MIN;
// 	char *str = ft_itoa(n);
// 	printf("num len: %d\nstring: %s\n", ft_numlen(n), str);
// 	return (0);
// }