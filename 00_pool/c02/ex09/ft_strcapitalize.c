/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:15:01 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/17 14:15:04 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	alphanumeric(char c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first;

	i = 0;
	first = 1;
	while (str[i])
	{
		if (alphanumeric(str[i]))
		{
			if (first && str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			else if (!first && str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			first = 0;
		}
		else
			first = 1;
		i++;
	}
	return (str);
}
