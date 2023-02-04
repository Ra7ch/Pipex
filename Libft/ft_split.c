/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:42:54 by raitmous          #+#    #+#             */
/*   Updated: 2023/01/13 12:33:42 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != 0)
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static char	*ft_word(char const *s, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (0);
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			word[j] = s[i];
		if (s[i] == c)
			break ;
		i++;
		j++;
	}
	word[j] = 0;
	return (word);
}

static void	ft_free(char **r, int i)
{
	while (i >= 0)
	{
		free(r[i]);
		i--;
	}
}

static char	**ft_r(char **r, char const *s, char c)
{
	int	j;

	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == 0)
			break ;
		r[j] = ft_word(s, c);
		if (!r[j])
			ft_free(r, j);
		while (*s != c && *s != '\0')
			s++;
		j++;
	}
	r[j] = 0;
	return (r);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**r;

	if (!s)
		return (0);
	r = (char **)malloc((ft_count(s, c) + 1) * sizeof(*r));
	if (!r)
		return (0);
	i = 0;
	j = 0;
	r = ft_r(r, s, c);
	return (r);
}
