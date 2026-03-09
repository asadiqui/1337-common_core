/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 01:10:30 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/19 01:10:42 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (!to_find[i])
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j] && to_find[j] == str[i + j])
			j++;
		if (!to_find[j])
			return (str + i);
		else
			i++;
	}
	return (0);
}
