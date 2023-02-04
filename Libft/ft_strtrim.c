/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:03:59 by raitmous          #+#    #+#             */
/*   Updated: 2022/10/26 01:06:52 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_check_d(char c, char const *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

static char	*ft_result1(char *r, char const *s1, int len, int i)
{
	int	j;

	j = 0;
	while (j < len + 1)
	{
		r[j] = s1[j + i];
		j++;
	}
	r[j - 1] = 0;
	return (r);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	while (s1[i] && ft_check_d(s1[i], set))
		i++;
	while (s1[j])
		j++;
	j--;
	while (j >= 0 && ft_check_d(s1[j], set))
		j--;
	len = j - i + 1;
	if (len < 0)
		len = 0;
	r = (char *)malloc(len + 1);
	if (!r)
		return (0);
	j = 0;
	r = ft_result1(r, s1, len, i);
	return (r);
}
