/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:34:45 by raitmous          #+#    #+#             */
/*   Updated: 2023/01/14 17:37:50 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(char *str)
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

static char	*ft_result(char *r, char const *s)
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

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	r = (char *)malloc(ft_strlen2(s1) + ft_strlen2(s2) + 1);
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
	while (j < ft_strlen2(s2))
	{
		ft_result(r, s1);
		r[ft_strlen2(s1) + j] = s2[j];
		j++;
	}
	free(s1);
	return (r);
}

int	ft_strchr2(char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (char)c)
			return (1);
		str++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	unsigned int	i;

	i = 0;
	if (size && count > SIZE_MAX / size)
		return (0);
	p = malloc(count * size);
	if (!p)
		return (0);
	while (i < count * size)
	{
		((unsigned char *)p)[i] = 0;
		i++;
	}
	return (p);
}
