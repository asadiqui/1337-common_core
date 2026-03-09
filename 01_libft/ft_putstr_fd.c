/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:23:05 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/16 20:32:17 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <string.h>
// int main() {
// 	int fd = open(".tst.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
// 	const char* msg = "Hello World!";
// 	write(fd, msg, strlen(msg));
// 	close(fd);
// 	return 0;
// }