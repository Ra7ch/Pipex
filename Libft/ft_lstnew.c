/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:33:49 by raitmous          #+#    #+#             */
/*   Updated: 2023/01/07 10:34:37 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*i;

	i = (t_list *)malloc(sizeof(t_list));
	if (!i)
		return (0);
	i->content = content;
	i->next = 0;
	i->previous = 0;
	return (i);
}
