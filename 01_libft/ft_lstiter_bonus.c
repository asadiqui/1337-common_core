/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadiqui <asadiqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:04:41 by asadiqui          #+#    #+#             */
/*   Updated: 2023/11/18 15:33:21 by asadiqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// Iterates the list & applies the function ’f’

// void	f(void *x)
// {
// 	*(int *)x *= 0;
// 	return ;
// }
// int main()
// {
// 	t_list *new1 = malloc(sizeof(t_list));
// 	t_list *new2 = malloc(sizeof(t_list));
// 	int nbr1 = 10; int nbr2 = 20;
// 	new1->content = &nbr1;
// 	new2->content = &nbr2;
// 	new1->next = new2;
// 	new2->next = NULL;
// 	printf("%d\t%d\n", *(int *)new1->content, *(int *)new2->content);
// 	ft_lstiter(new1, f);
// 	printf("%d\t%d\n", *(int *)new1->content, *(int *)new2->content);
// }