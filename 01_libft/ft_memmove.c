/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:18:26 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/18 13:54:11 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src == dst)
		return (dst);
	if (dst > src)
	{
		i = len;
		while (i--)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	else
	{
		i = 0;
		while (i++ < len)
			((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
	}
	return (dst);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char dst[5];
// 	// char *src = "alohha";
// 	printf("%s\n", memmove(dst, NULL, 4));
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main()
// {
// 	char	s1[30] = "abcdefghijklmnopqrstuvwxyz";
// 	printf("dst: %s\n", s1+5);
// 	printf("src: %s\n", s1);
// 	ft_memmove(s1+5, s1, 10);
// 	printf("ft_memmove result: %s\n", s1);
// 	char	s2[30] = "abcdefghijklmnopqrstuvwxyz";
// 	memmove(s2+5, s2, 10);
// 	printf("   memmove result: %s\n", s2);
// 	char	s3[30] = "abcdefghijklmnopqrstuvwxyz";
// 	memcpy(s3+5, s3, 10);
// 	printf("   memcpy  result: %s\n", s3);
// }