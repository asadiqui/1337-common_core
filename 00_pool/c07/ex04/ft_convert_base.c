/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:02:05 by asadiqui          #+#    #+#             */
/*   Updated: 2023/08/02 18:02:06 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putnbr_base(int nbr, char *base, char *nbrf);
int		ft_atoi_base(char *str, char *base);
int		ft_n_len(int nbr, char *base);

int	valid(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '
			|| str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	atoi_valid(char *str, int *ptr_i)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while ((str[i] != '\0') && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*ptr_i = i;
	return (sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		mednbr;
	int		lenght_nbrf;

	if (!valid(base_to) || !valid(base_from))
		return (0);
	mednbr = ft_atoi_base(nbr, base_from);
	lenght_nbrf = ft_n_len(mednbr, base_to);
	result = (char *)malloc(sizeof(char) * (lenght_nbrf + 1));
	if (!result)
		return (0);
	ft_putnbr_base(mednbr, base_to, result);
	result[lenght_nbrf] = '\0';
	return (result);
}
/*
#include <stdio.h>
int	main(int ac,  char **av)
	{(void)ac;
	char *str = ft_convert_base(av[1], av[2], av[3]);
	printf("%s\n", str);}*/
