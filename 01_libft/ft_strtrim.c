/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:06:28 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/18 22:16:50 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end] && ft_strchr(set, s1[end]) && end > start)
		end--;
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 2);
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	char *s1 = "1234abdallah1234"; //s1
// 	char *set = "1234"; //set
// 	char *str = ft_strtrim(s1, set);
// 	printf("%s\n", str);
// }

// this implementation is working, only it mallocs
// more memory than it's needed, using free is forbideen
// it uses ft_strrev to reverse the sting and
// start trimming from the end (reversed start)
// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char	*str;

// 	while (*s1 && ft_strchr(set, *s1))
// 		s1++;
// 	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
// 	if (!str)
// 		return (NULL);
// 	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
// 	ft_strrev(str);
// 	while (*str && ft_strchr(set, *str))
// 		str++;
// 	ft_strrev(str);
// 	return (str);
// }
