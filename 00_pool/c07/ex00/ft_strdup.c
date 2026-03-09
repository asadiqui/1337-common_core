/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:50:35 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/24 21:50:37 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*cpy;

	len = 0;
	while (src[len])
		len++;
	cpy = malloc(len * sizeof(char) + 1);
	if (!cpy)
		return (0);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
/*
#include <stdio.h>
int	main()
{
	printf("%s", ft_strdup("Hello World!"));
	return (0);
}*/
