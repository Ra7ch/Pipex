/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:31:34 by raitmous          #+#    #+#             */
/*   Updated: 2023/01/07 10:39:17 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int *(*f)(int), void (*del)(int))
{
	t_list	*tmp;
	t_list	*head;

	head = 0;
	while (lst)
	{
		tmp = ft_lstnew(*(*f)(lst->content));
		if (!tmp)
		{
			while (head)
			{
				tmp = head->next;
				(*del)(head->content);
				free(head);
				head = tmp;
			}
			return (0);
		}
		ft_lstadd_back(&head, tmp);
		lst = lst->next;
	}
	return (head);
}
