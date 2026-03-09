/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:39:23 by asadiqui          #+#    #+#             */
/*   Updated: 2023/12/04 15:58:58 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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