/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:35:13 by raitmous          #+#    #+#             */
/*   Updated: 2022/10/24 22:35:19 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t l)
{
	unsigned char	*str;
	unsigned int	i;

	i = 0;
	str = (unsigned char *)s;
	while (i < l)
	{
		if (*str != (unsigned char)c && i < l)
		{
			str++;
			i++;
		}
		else
			return (str);
	}
	return (0);
}
