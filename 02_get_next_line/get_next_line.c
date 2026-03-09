/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:51:57 by asadiqui          #+#    #+#             */
/*   Updated: 2023/12/04 22:44:54 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(int i, ...)
{
	va_list	args;

	va_start(args, i);
	while (i--)
		free(va_arg(args, char *));
	va_end(args);
	return (NULL);
}

char	*read_from_fd(int fd, char *buff)
{
	char	*tmp;
	ssize_t	bytes_read;

	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (buff)
				return (ft_free(2, tmp, buff));
			return (ft_free(1, tmp));
		}
		tmp[bytes_read] = '\0';
		buff = ft_strjoin(buff, tmp);
		if (ft_strchr(buff, '\n') || bytes_read < BUFFER_SIZE)
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

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
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

// int	main(void)
// {
// 	int		fd;
// 	int		i = 1;
// 	char	*buff;

// 	fd = open(".macos", O_RDONLY);
// 	while (i <= 5)
// 	{
// 	 	buff = get_next_line(fd);
// 		printf("line %02d:\t%s", i, buff);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }

// - read to static buff while !\n
// - get_line (up to \n) from buff
// - get new_buff (up to \0)