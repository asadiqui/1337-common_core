/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:38:42 by asadiqui          #+#    #+#             */
/*   Updated: 2023/12/04 16:04:50 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
	static char	*buff[OPEN_MAX];
	char		*line;
	char		*tmp;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = read_from_fd(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	i = 0;
	while (buff[fd][i] != '\n' && buff[fd][i] != '\0')
		i++;
	line = ft_substr(buff[fd], 0, i + 1);
	tmp = ft_substr(buff[fd], i + 1, ft_strlen(buff[fd]) - i - 1);
	ft_strlcpy(buff[fd], tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (line);
}

// int	main(void)
// {
// 	int		fd1, fd2, fd3;
// 	int		i = 1;
// 	char	*buff;

// 	fd1 = open("1.txt", O_RDONLY);
// 	fd2 = open("2.txt", O_RDONLY);
// 	fd3 = open("3.txt", O_RDONLY);
// 	while (i <= 10)
// 	{
// 	 	buff = get_next_line(fd1);
// 		printf("line %02d:\tfd %02d:\t%s", i, fd1, buff);
// 		buff = get_next_line(fd2);
// 		printf("line %02d:\tfd %02d:\t%s", i, fd2, buff);
// 		buff = get_next_line(fd3);
// 		printf("line %02d:\tfd %02d:\t%s", i, fd3, buff);
// 		i++;
// 	}
// 	close(fd1);close(fd2);close(fd3);
// 	return (0);
// }