/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:36:27 by raitmous          #+#    #+#             */
/*   Updated: 2023/01/13 12:33:11 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)src;
	str2 = dest;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < size)
	{
		str2[i] = str1[i];
		i++;
	}
	dest = str2;
	return (dest);
}
