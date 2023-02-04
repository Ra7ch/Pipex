/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:03:15 by raitmous          #+#    #+#             */
/*   Updated: 2022/10/24 16:03:45 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_bzero(void *dest, size_t size)
{
	unsigned int	i;
	char			*str;

	str = dest;
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	dest = str;
	return (dest);
}
