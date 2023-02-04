/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:16:57 by raitmous          #+#    #+#             */
/*   Updated: 2022/10/26 01:06:01 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	allocation(char const *s, unsigned int start, size_t len)
{
	unsigned long	w;

	w = ft_strlen(s);
	if (start >= w)
		return (1);
	if (w + 1 == start + len)
		return (len);
	if (len > w)
		return (w - start + 1);
	return (len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	sub = (char *)malloc(allocation(s, start, len));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (!sub)
		return (0);
	while (s[i] && j < len)
	{
		if (i >= start)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = 0;
	return (sub);
}
