/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:28:45 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/23 14:28:48 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	pow;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	pow = 1;
	while (power > 0)
	{
		pow *= nb;
		power--;
	}
	return (pow);
}
