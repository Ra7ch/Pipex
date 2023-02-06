/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_paths_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:43:33 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/06 03:59:17 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	check_access(char *cmd)
{
	char	*s;

	s = ft_strjoin("./", cmd);
	if (access(s, F_OK) == 0)
		return (free(s), 1);
	else
		return (free(s), 0);
}

void	if_its_command(char *cmd, char **s, char **paths)
{
	int		pid;
	int		status;
	char	**c;
	int		*fd;

	fd = malloc(2 * 4);
	pipe(fd);
	c = malloc(2 * 8);
	pid = fork();
	if (pid == 0)
	{
		c[0] = cmd;
		c[1] = NULL;
		dup2(fd[1], 1);
		execve(c[0], c, NULL);
		close(fd[1]);
		close(fd[0]);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Command not found\n", 2);
		free(c);
		exit(1);
	}
	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) != 0)
		(free(c), ft_free(s), free(s), ft_free(paths), exit(127));
}
