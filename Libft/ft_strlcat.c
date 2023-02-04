/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:57:16 by raitmous          #+#    #+#             */
/*   Updated: 2022/10/25 12:41:13 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d;
	size_t	s;

	j = 0;
	i = 0;
	s = 0;
	if (dest)
		j = ft_strlen(dest);
	s = ft_strlen(src);
	d = j;
	if (size == 0 || size <= d)
		return (s + size);
	while (src[i] && i < size - d - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (d + s);
}
