/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:34:12 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/06 02:43:56 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_lewel(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i++;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_tani(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (str[i + j])
	{
		s[j] = str[i + j];
		j++;
	}
	s[j] = '\0';
	free(str);
	return (s);
}

char	*ft_kamel(int fd, char *s)
{
	char	*buf;
	int		i;
	int		j;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr2(s, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1 || i == 0)
			break ;
		buf[i] = '\0';
		if (!s && !buf[0])
		{
			free(buf);
			return (NULL);
		}
		j = ft_strlen2(s) + ft_strlen2(buf);
		s = ft_strjoin2(s, buf);
		s[j] = 0;
	}
	free(buf);
	return (s);
}

int	get_next_line(int fd, char **l)
{
	char		*s;
	static char	*st;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (-1);
	s = ft_kamel(fd, st);
	if (!s)
		return (0);
	*l = ft_lewel(s);
	st = ft_tani(s);
	return (0);
}
