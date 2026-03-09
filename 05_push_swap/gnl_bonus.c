/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c			                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:57:55 by asadiqui          #+#    #+#             */
/*   Updated: 2024/01/10 20:58:07 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*ft_free(int i, ...)
{
	va_list	args;

	va_start(args, i);
	while (i--)
		free(va_arg(args, char *));
	va_end(args);
	return (NULL);
}

static char	*read_from_fd(int fd, char *buff)
{
	char	*tmp;
	ssize_t	bytes_read;

	tmp = malloc(sizeof(char) * 1 + 1);
	if (!tmp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, 1);
		if (bytes_read < 0)
		{
			if (buff)
				return (ft_free(2, tmp, buff));
			return (ft_free(1, tmp));
		}
		tmp[bytes_read] = '\0';
		buff = ft_strjoin(buff, tmp);
		if (ft_strchr(buff, '\n') || bytes_read < 1)
			break ;
	}
	if (buff[0] == '\0')
		return (ft_free(2, tmp, buff));
	free(tmp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	char		*tmp;
	size_t		i;

	buff = read_from_fd(fd, buff);
	if (!buff)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	line = ft_substr(buff, 0, i + 1);
	tmp = ft_substr(buff, i + 1, ft_strlen(buff) - i - 1);
	ft_strlcpy(buff, tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (line);
}
