/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:37:06 by raitmous          #+#    #+#             */
/*   Updated: 2022/10/24 22:37:50 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	check(char *des, char *sr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sr == des + i)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_move1(char *des, char *sr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		des[i] = sr[i];
		i++;
	}
	return (des);
}

static char	*ft_move2(char *des, char *sr, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		des[i] = sr[i];
		i--;
	}
	return (des);
}

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*sr;
	char	*des;

	sr = (char *)src;
	des = dest;
	if (!des && !sr)
		return (0);
	if (check(des, sr, size))
		des = ft_move1(des, sr, size);
	else if (!check(des, sr, size))
		des = ft_move2(des, sr, size);
	dest = des;
	return (dest);
}
