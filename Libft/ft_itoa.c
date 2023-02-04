/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:10:16 by raitmous          #+#    #+#             */
/*   Updated: 2022/10/24 16:10:46 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_len(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (n < 10)
		i++;
	return (i);
}

static char	*ftitoa(long c, char *s)
{
	while (c >= 10)
	{
		*s = c % 10 + 48;
		c = c / 10;
		s--;
	}
	if (c < 10)
		*s = c + 48;
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	long	c;
	int		w;

	i = 0;
	c = n;
	s = malloc(ft_len(n) + 1);
	if (!s)
		return (0);
	if (c < 0)
	{
		*s = '-';
		s++;
		c = -c;
	}
	w = ft_len(c);
	s = s + ft_len(c) - 1;
	s = ftitoa(c, s);
	s[w] = 0;
	if (n < 0)
		s--;
	return (s);
}
