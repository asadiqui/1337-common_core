/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:25:01 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/27 01:25:04 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	convert(char *str, char *base, int len)
{
	int	i;
	int	j;
	int	result;

	result = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				result *= len;
				result += j;
				j++;
				break ;
			}
			else
				j++;
		}
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	sign;

	len = 0;
	while (base[len])
		len++;
	if (len <= 1 || !str)
		return (0);
	if (!valid(base))
		return (0);
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (convert(str, base, len) * sign);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi_base("	+++++--133742", "0123456789"));
	printf("%d\n", ft_atoi_base("	     ---101010", "01"));
	printf("%d\n", ft_atoi_base(" 	+---539", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("ff", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("2147483647", "0123456789"));
	printf("%d\n", ft_atoi_base("-2147483648", "0123456789"));
}*/
