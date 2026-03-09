/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:28:28 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/20 10:08:14 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

// int main()
// {
// 	char dst[5];
// 	// char *src = "alohha";
// 	printf("%s\n", ft_memcpy(dst, NULL, 4));
// }
// int main()
// {
// 	char *dst = "Hello";
// 	char *src = "Hello";
// 	ft_memcpy(dst, src, 4);
// 	printf("%s\n", dst);
// }
