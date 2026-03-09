/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:33:43 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/18 22:14:17 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*crntnode;
	void	*cntnt;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		cntnt = f(lst->content);
		crntnode = ft_lstnew(cntnt);
		if (!crntnode)
		{
			del(cntnt);
			ft_lstclear(&newlst, del);
			return (newlst);
		}
		ft_lstadd_back(&newlst, crntnode);
		lst = lst->next;
	}
	return (newlst);
}
// void	*f(void *data)
// {
// 	*(int *)data *= 10;
// 	return (data);
// }
// void	del(void *data)
// {
// 	free(data);
// }
// int	main()
// {
// 	t_list	*nd1 = malloc(sizeof(t_list));
// 	t_list	*nd2 = malloc(sizeof(t_list));
// 	t_list	*nd3 = malloc(sizeof(t_list));
// 	t_list	*new;
// 	int		nbr1 = 10;
// 	int		nbr2 = 20;
// 	int		nbr3 = 30;

// 	nd1->next = nd2;
// 	nd2->next = nd3;
// 	nd3->next = NULL;
// 	nd1->content = &nbr1;
// 	nd2->content = &nbr2;
// 	nd3->content = &nbr3;

// 	new = ft_lstmap(nd1, f, del);
// 	while (new)
// 	{
// 		printf("%d\n", *(int *)new->content);
// 		new = new->next;
// 	}
// 	return  (0);
// }
// create new list from existing one