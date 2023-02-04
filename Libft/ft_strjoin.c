/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:54:35 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/04 22:47:57 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlength(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_result(char *r, char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	return (r);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	r = (char *)malloc(ft_strlength(s1) + ft_strlength(s2) + 1);
	if (!r)
		return (0);
	if (!s1)
		return (ft_result(r, s2));
	if (!s2)
		return (ft_result(r, s1));
	if (s2[0] == 0)
		ft_result(r, s1);
	if (s1[0] == 0)
		ft_result(r, s2);
	while (j < ft_strlength(s2))
	{
		ft_result(r, s1);
		r[ft_strlength(s1) + j] = s2[j];
		j++;
	}
	r[ft_strlength(s1) + j] = 0;
	return (r);
}
