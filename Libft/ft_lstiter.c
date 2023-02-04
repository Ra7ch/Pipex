/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:28:57 by raitmous          #+#    #+#             */
/*   Updated: 2023/01/07 10:36:51 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list	*tmp;

	tmp = lst;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
	lst = tmp;
}
