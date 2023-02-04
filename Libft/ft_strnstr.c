/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:00:06 by raitmous          #+#    #+#             */
/*   Updated: 2022/10/25 14:29:33 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *hay, const char *ne, size_t l)
{
	char			*h;
	char			*n;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	h = (char *)hay;
	n = (char *)ne;
	if ((!h || !n) && l == 0)
		return (0);
	if (n[i] == 0)
		return (h);
	if (ft_strlen(hay) < l)
		l = ft_strlen(hay);
	while (h[i] && i < l)
	{
		j = 0;
		while ((h[i + j] == n[j]) && i + j < l)
			j++;
		if (n[j] == 0)
			return (h + i);
		i++;
	}
	return (0);
}
