/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:00:18 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/14 15:44:48 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	j;
	size_t	i;

	if (!s)
		return (NULL);
	j = start;
	if (j >= ft_strlen(s))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && j < ft_strlen(s))
		str[i++] = s[j++];
	str[i] = 0;
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	char *s1 = "hola";
// 	int start = -1;
// 	int len = -1;
// 	char *s2 = ft_substr(s1, start, len);
// 	printf("%s\n", s2);
// }
