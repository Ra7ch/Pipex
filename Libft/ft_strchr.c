/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:48:23 by raitmous          #+#    #+#             */
/*   Updated: 2022/10/24 22:48:43 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *str, int c)
{
	if ((unsigned char)c == '\0')
	{
		while (*str)
			str++;
		return ((char *)str);
	}
	if ((unsigned char)c > 255 || (unsigned char)c < 0)
		return (0);
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	return (0);
}
