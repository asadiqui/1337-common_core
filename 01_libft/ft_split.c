/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:52:37 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/15 20:37:42 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] && *strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

static int	count_words(char const *str, char c)
{
	int	count;

	count = 1;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static char	*put_word(char const *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	i = 0;
	while (*str && *str != c)
		word[i++] = *str++;
	word[i] = 0;
	return (word);
}

static char	**put_strings(char **strings, char const *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			strings[i] = put_word(str, c);
			if (strings[i] == NULL)
			{
				free_strings(strings);
				return (0);
			}
			i++;
		}
		while (*str && *str != c)
			str++;
	}
	strings[i] = 0;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;

	if (!s)
		return (NULL);
	strings = malloc(sizeof(char *) * count_words(s, c));
	if (!strings)
		return (0);
	strings = put_strings(strings, s, c);
	return (strings);
}

// #include <stdio.h>
// int main()
// {
// 	char	*str = "  Hello World!  ";
// 	char	c = ' ';
// 	char	**strings = ft_split(str, c);
// 	int		i = 0;
// 	while (strings[i])
// 	{
// 		printf("%s\n", strings[i]);
// 		i++;
// 	}
// 	return (0);
// }