/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:02:17 by raitmous          #+#    #+#             */
/*   Updated: 2022/10/24 23:02:21 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
	{
		while (*str)
			str++;
		return ((char *)str);
	}
	if ((unsigned char)c > 255 || (unsigned char)c < 0)
		return (0);
	while (*str)
	{
		str++;
		i++;
	}
	while (i >= 0)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		i--;
		str--;
	}
	return (0);
}
