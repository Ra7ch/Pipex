/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:38:14 by raitmous          #+#    #+#             */
/*   Updated: 2022/10/24 22:38:28 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_memset(void *dest, int c, size_t size)
{
	unsigned int	i;
	char			*str;

	str = dest;
	i = 0;
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	dest = str;
	return (dest);
}
