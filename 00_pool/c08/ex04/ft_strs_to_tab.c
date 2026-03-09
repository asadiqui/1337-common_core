/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:37:39 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/26 01:37:42 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
/*
typedef struct s_stock_str
{
int size;
char *str;
char *copy;
} t_stock_str;*/

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
/*
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}*/

char	*ft_strdup(char *src)
{
	int		i;
	char	*cpy;

	cpy = malloc(ft_strlen(src) * sizeof(char) + 1);
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

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*array;

	array = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = av[i];
		array[i].copy = ft_strdup(array[i].str);
		i++;
	}
	array[ac].size = 0;
	array[ac].str = NULL;
	array[ac].copy = NULL;
	return (array);
}
/*if (!array[i].copy)
		{
			j = 0;
			while (j < i)
				free(array[j].copy);
			free(array);
			return (NULL);
		}*/
/*
typedef struct s_stock_str
{
	int size;
	char *str;
	char *copy;
} t_stock_str;
struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void ft_show_tab(struct s_stock_str *par);

int main()
{
	char *strings[] = {"Hello", "World", "ChatGPT"};
    t_stock_str *array = ft_strs_to_tab(3, strings);
	ft_show_tab(array);
}*/
