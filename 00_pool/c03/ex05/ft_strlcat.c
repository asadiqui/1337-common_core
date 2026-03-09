/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:47:22 by asadiqui          #+#    #+#             */
/*   Updated: 2023/07/18 20:47:26 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dstlen;
	unsigned int	srclen;
	unsigned int	rtrn;
	unsigned int	i;

	dstlen = 0;
	srclen = 0;
	while (dest[dstlen])
		dstlen++;
	while (src[srclen])
		srclen++;
	if (dstlen < size)
		rtrn = srclen + dstlen;
	else
		rtrn = srclen + size;
	if (size == 0)
		return (rtrn);
	i = 0;
	while (src[i] && i < size - dstlen - 1)
	{
		dest[dstlen + i] = src[i];
		i++;
	}
	dest[dstlen + i] = '\0';
	return (rtrn);
}
