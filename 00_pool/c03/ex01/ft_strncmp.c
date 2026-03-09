/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:53:29 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/17 17:53:33 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && n)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}
