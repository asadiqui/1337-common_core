/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:03:06 by asadiqui          #+#    #+#             */
/*   Updated: 2023/12/01 18:20:36 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	main(void)
{
	// # ===> x,X
	// + ===> d,i
	// ' ' ===> d,i
	int nft = 0; int n = 0;
	// mandatory part
	// nft += ft_printf("%c %s %d %i %u %x %X %p %%\n", 'a', "Hello", 42, 42, -42, 42, 42, main);
	// n +=	  printf("%c %s %d %i %u %x %X %p %%\n", 'a', "Hello", 42, 42, -42, 42, 42, main);
	// nft += ft_printf("%c %s %d %i %u %x %X %p\n", 0, NULL, 0, 0, 0, 0, 0, NULL);
	// n +=	  printf("%c %s %d %i %u %x %X %p\n", 0, NULL, 0, 0, 0, 0, 0, NULL);
	// bonus part #
	nft += ft_printf("%#x %#X %#%\n", 42, 42);
	n +=	  printf("%#x %#X %#%\n", 42, 42);
	// bonus part +
	nft += ft_printf("%+d %+i %+%\n", -42, 42);
	n +=	  printf("%+d %+i %+%\n", -42, 42);
	// bonus part ' '
	nft += ft_printf("% d % i % %\n", -42, 42);
	n +=	  printf("% d % i % %\n", -42, 42);
	printf("%d, %d\n", nft, n);
	return (0);
}
