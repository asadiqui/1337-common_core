/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:30:16 by asadiqui          #+#    #+#             */
/*   Updated: 2023/12/07 14:29:36 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*##############################*|
|*           HEADERS            *|
|*##############################*/

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>

/*##############################*|
|*            MACROS            *|
|*##############################*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
/* the maximum value BUFFER_SIZE
 * can hold is 9223372016854775807
 * (63 bits) being SSIZE_MAX
 * it's architecture-dependant */

/*##############################*|
|*       MAIN_FUNCTIONS         *|
|*##############################*/

char	*get_next_line(int fd);
char	*get_new_buff(char *buff);
char	*ft_free(int i, ...);

/*##############################*|
|*            LIBFT             *|
|*##############################*/

size_t	ft_strlen(const char *str);
int		ft_strchr(const char *s, int c);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
