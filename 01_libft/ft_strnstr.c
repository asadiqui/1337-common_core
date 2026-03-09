/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:51:36 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/15 20:20:45 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len && needle[j])
			j++;
		if (!needle[j])
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	char	*haystack = "A";
// 	char	*needle = "A";
// 	size_t	len = ft_strlen(haystack) + 1;
// 	char	*s1 = ft_strnstr(haystack, needle, len);
// 	char	*s2 = strnstr(haystack, needle, len);
// 	printf("%s\n%s\n", s1, s2);
// }