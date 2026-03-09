/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:30:15 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/23 14:30:17 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 0 || nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	while (i <= (nb / i))
	{
		if (!(nb % i))
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
}

/*
int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	return(ft_find_next_prime(nb + 1));
}*/