/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kamel_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:54:21 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/04 23:16:50 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_kamel_condition(char *s, char **argv)
{
	char	*buf;

	if (s && ft_strlen(s) >= ft_strlen(argv[2]))
	{
		if (ft_strlen(s) == ft_strlen(argv[2]) + 1)
		{
			buf = ft_strjoin(argv[2], "\n");
			if (!ft_memcmp(buf, s, ft_strlen(s)))
				return (free(buf), 1);
			free(buf);
		}
		buf = ft_strjoin("\n", argv[2]);
		if (!ft_memcmp(buf, s + (ft_strlen(s) - ft_strlen(buf) - 1),
				ft_strlen(buf)))
			return (free(buf), 1);
		free(buf);
	}
	return (0);
}

char	*ft_kamel(int fd, char **argv)
{
	char	buf[5];
	char	*tmp;
	char	*s;
	int		i;
	int		j;

	s = NULL;
	i = 1;
	while (!ft_kamel_condition(s, argv))
	{
		i = read(fd, buf, 4);
		if (i == -1)
			break ;
		buf[i] = '\0';
		if (!s && !buf[0])
			return (NULL);
		j = ft_strlen(buf);
		if (s)
			j = j + ft_strlen(s);
		tmp = s;
		s = ft_strjoin(s, buf);
		free(tmp);
		s[j] = 0;
	}
	return (s);
}
