/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:43:33 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/03 20:48:55 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	complete_path(char **path)
{
	char	*tmp;
	int		i;

	i = 0;
	while (path[i])
	{
		tmp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		free(tmp);
		i++;
	}
}

char	**paths(char **env)
{
	int		n;
	int		i;
	char	**path;

	i = 1;
	n = 0;
	while (env[n])
	{
		i = ft_memcmp("PATH=", env[n], 5);
		if (i == 0)
			break ;
		n++;
	}
	if (env[n] == NULL)
	{
		path = malloc(1 * sizeof(char *));
		path[0] = NULL;
		return (path);
	}
	env[n] = env[n] + 5;
	path = ft_split(env[n], ':');
	complete_path(path);
	return (path);
}
