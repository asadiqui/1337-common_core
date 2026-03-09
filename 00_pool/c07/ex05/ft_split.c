/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:30:38 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/30 15:30:41 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ck_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int	word_len(char *str, char *sep)
{
	int	len;

	len = 0;
	while (*str && !ck_sep(*str, sep))
	{
		len++;
		str++;
	}
	return (len);
}

char	*put_word(char *str, char *sep)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = word_len(str, sep);
	word = malloc(sizeof(char) * (len + 1));
	while (*str && i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	words_count(char *str, char *sep)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ck_sep(*str, sep))
			str++;
		if (*str)
			count++;
		while (*str && !ck_sep(*str, sep))
			str++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		i;

	array = malloc(sizeof(char *) * (words_count(str, charset) + 1));
	if (!array)
		return (0);
	i = 0;
	while (*str)
	{
		while (*str && ck_sep(*str, charset))
			str++;
		if (*str)
		{
			array[i] = put_word(str, charset);
			i++;
		}
		while (*str && !ck_sep(*str, charset))
			str++;
	}
	array[i] = 0;
	return (array);
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
	(void)ac;
	char **array = ft_split(av[1], av[2]);
	while (*array)
	{
		printf("%s\n", *array);
		array++;
	}
}*/