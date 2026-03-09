/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:51:35 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/24 21:51:37 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	total_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += ft_strlen(sep) * (size - 1) + 1;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		pos;
	int		i;

	if (!size)
		return (str = malloc(sizeof(char)));
	str = malloc(total_len(size, strs, sep));
	if (!str)
		return (0);
	i = 0;
	pos = 0;
	while (i < size)
	{
		ft_strcpy(&str[pos], strs[i]);
		pos += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(&str[pos], sep);
			pos += ft_strlen(sep);
		}
		i++;
	}
	str[pos] = '\0';
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char	*strs[] = {"Hello", "World", "Who am i?"};
	char *str = ft_strjoin(3, strs, ", ");
	printf("%s\n", str);
	free(str);
	return 0;
}*/
