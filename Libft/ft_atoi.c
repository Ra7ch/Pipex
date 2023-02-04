/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:59:36 by raitmous          #+#    #+#             */
/*   Updated: 2023/01/14 23:43:52 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ftatoi(char *s)
{
	long long	i;
	long long	j;
	int			sign;
	long long	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	sign = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			sign = 1;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		tmp = tmp * 10 + s[i] - '0';
		if (tmp > 2147483647 + (long long)(sign))
			return (2147483648);
		j = tmp;
		i++;
	}
	if (sign)
		j = j * -1;
	return (j);
}

long long	ft_atoi(char *str)
{
	char		*s;
	long long	i;
	long long	sign;
	int			r;

	s = (char *)str;
	i = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\r' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\f')
		i++;
	sign = 1;
	r = ftatoi(s + i);
	return (r);
}
