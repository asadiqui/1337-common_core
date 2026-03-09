/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:02:14 by asadiqui          #+#    #+#             */
/*   Updated: 2023/08/02 18:02:15 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid(char *str);
int	atoi_valid(char *str, int *ptr_i);

int	base_pos(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-42);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	nb;
	int	nb2;
	int	base_len;

	nb = 0;
	i = 0;
	base_len = valid(base);
	if (base_len >= 2)
	{
		sign = atoi_valid(str, &i);
		nb2 = base_pos(str[i], base);
		while (nb2 != -42)
		{
			nb = (nb * base_len) + nb2;
			i++;
			nb2 = base_pos(str[i], base);
		}
		return (nb *= sign);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_n_len(int nbr, char *base)
{
	int				base_len;
	unsigned int	nb;
	int				n_len;

	n_len = 0;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		nb = nbr * -1;
		n_len++;
	}
	else
		nb = nbr;
	while (nb >= (unsigned)base_len)
	{
		nb /= base_len;
		n_len++;
	}
	n_len++;
	return (n_len);
}

void	ft_putnbr_base(int nbr, char *base, char *str)
{
	int		base_len;
	long	nb;
	int		i;
	int		n_len;

	base_len = ft_strlen(base);
	n_len = ft_n_len(nbr, base);
	nb = nbr;
	i = 0;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
		i = 1;
	}
	n_len--;
	while (nb >= base_len)
	{
		str[n_len] = base[nb % base_len];
		nb /= base_len;
		n_len--;
	}
	if (nb < base_len)
		str[i] = base[nb];
}
