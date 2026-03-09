/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:14:09 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/20 10:08:23 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len--)
		str[len] = (unsigned char)c;
	return (b);
}
int main()
{
	int  arr[2]  = {0,0};
	memset(arr,2,5);
	for(int i=0;i < 4;i++)
	printf("%d\n",arr[i]);
}
int main()
{ // 0,1,2,3 ==> 0,1,1337,3
	int arr[] = {0,1,2,3};
	// ft_memset(&arr[2], 5, 2);
	// ft_memset(&arr[2], 57, 1);
// if u want to represent nv, consider overflow
	// ft_memset(arr, 255, 4);
	// ft_memset(arr, 250, 2);
	// ft_memset(arr, 199, 1);
	for (int i=0; i < 4; i++)
		printf("%d\n",arr[i]);
	return (0);
}