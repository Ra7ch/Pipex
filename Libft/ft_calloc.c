/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:04:31 by raitmous          #+#    #+#             */
/*   Updated: 2022/10/26 00:59:42 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	unsigned int	i;

	i = 0;
	if (size && count > SIZE_MAX / size)
		return (0);
	p = malloc(count * size);
	if (!p)
		return (0);
	while (i < count * size)
	{
		((unsigned char *)p)[i] = 0;
		i++;
	}
	return (p);
}
