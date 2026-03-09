/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:30:04 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/16 20:32:03 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	str[12];
	int		is_neg;

	if (fd < 0)
		return ;
	is_neg = (n < 0);
	ft_bzero(str, 12);
	if (n == 0)
		str[0] = '0';
	i = 0;
	while (n)
	{
		str[i++] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	if (is_neg)
		str[i] = '-';
	else if (i > 0)
		i--;
	while (i >= 0)
		write(fd, &str[i--], 1);
}

// void	ft_putnbr_fd(int n, int fd)
// {
// 	write(fd, ft_itoa(n), ft_nbrlen(n));
//	error bcz u'r allocating mry with ft_itoa;
// }