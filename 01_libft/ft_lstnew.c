/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:10:06 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/12 15:51:55 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

// initialize a node
// #include <stdio.h>
// int main()
// {
// 	int content = 55;
// 	t_list *myList = ft_lstnew(&content);
// 	printf("%p\t%d\n", myList->content, *(int *)myList->content);
// 	return (0);
// }