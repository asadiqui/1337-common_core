/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:06:40 by asadiqui          #+#    #+#             */
/*   Updated: 2023/08/01 18:06:42 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	while (length)
	{
		f(*tab++);
		length--;
	}
}
/*
void	ft_putchar(char c){write(1, &c, 1);}
void	ft_putnbr(int nb)
{	if (nb == -2147483648) { write(1, "-2147483648", 11); return; }
	else if (nb < 0) { nb *= -1; ft_putchar('-'); ft_putnbr(nb); }
	else if (nb < 10) ft_putchar(nb + 48);
	else { ft_putnbr(nb / 10); ft_putnbr(nb % 10); } }
int main()
{	int	tab[] = {550, 17, 60, 90, 730, -85};
	int length = sizeof(tab) / sizeof(int);
	ft_foreach(tab, length, ft_putnbr);
	write(1, "\n", 1); }*/
