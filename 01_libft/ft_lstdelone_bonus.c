/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:19:14 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/18 15:33:39 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// delete and free a node
// void	del(void *cntt)
// {
// 	free(cntt);
// }
// int	main()
// {
// 	t_list	*new = malloc(sizeof(t_list));
// 	int	nbr = 10;
// 	new->content = &nbr;
// 	new->next = NULL;
// 	printf("%d\n", *(int *)new->content);
// 	ft_lstdelone(new, del);
// 	printf("%d\n", *(int *)new->content);
// 	return (0);
// }
