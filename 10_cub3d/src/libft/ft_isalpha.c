/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:54:06 by merrahal          #+#    #+#             */
/*   Updated: 2024/11/17 09:22:16 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_isalpha(char *str, int c)
{
	if ((str[0] == '+' || str[0] == '-') && str[1] == '\0')
	{
		printf("bad character in c or f\n");
		ffreeee(0, (*get_data()));
		_free();
		exit(1);
	}
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') || c == '+'
		|| c == '-' || !ft_isdigit(c))
	{
		printf("bad character in c or f\n");
		ffreeee(0, (*get_data()));
		_free();
		exit(1);
		return (1);
	}
	else
		return (0);
}
