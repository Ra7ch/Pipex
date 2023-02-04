/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:06:57 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/05 00:48:06 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute(char **commands, int j)
{
	char	**cmd;

	cmd = ft_split(commands[j], ' ');
	execve(cmd[0], cmd, NULL);
	perror(cmd[0]);
	ft_free(cmd);
	free(cmd);
	exit(126);
}

int	ft_fork(char **commands, int **fdp, char **paths, int j)
{
	int	pid;
	int	i;

	i = 0;
	while (commands[++i])
		;
	pid = fork();
	if (pid == 0)
	{
		check_command(commands, paths, j);
		close(fdp[j + 1][0]);
		if (fdp[j][0] == -1)
			exit(0);
		dup2(fdp[j][0], 0);
		if (j + 1 != i)
			dup2(fdp[j + 1][1], 1);
		else
			dup2(fdp[0][1], 1);
		execute(commands, j);
	}
	close(fdp[j][0]);
	close(fdp[j + 1][1]);
	return (pid);
}

void	ft_status(int *pid, int j, int **fdp)
{
	int	i;
	int	status;

	i = 0;
	close(fdp[0][1]);
	while (i < j)
	{
		//waitpid(pid[i], &status, 0);
		i++;
	}
	waitpid(pid[i - 1], &status, 0);
	free(pid);
	exit(WEXITSTATUS(status));
}

void	initialize(char **path, int **fdp, char **commands, char **argv)
{
	int	j;
	int	i;
	int	*pid;

	i = 0;
	while (commands[i])
		i++;
	fdp = malloc((i + 1) * sizeof(int *));
	pid = malloc(i * sizeof(int));
	fdp[0] = fd_files(argv);
	j = 1;
	while (j <= i)
	{
		fdp[j] = malloc(2 * sizeof(int));
		pipe(fdp[j]);
		j++;
	}
	j = 0;
	while (j + 1 <= i)
	{
		pid[j] = ft_fork(commands, fdp, path, j);
		j++;
	}
	ft_status(pid, j, fdp);
}

int	main(int argc, char **argv, char **env)
{
	int		**fdp;
	char	**path;
	char	**commands;

	fdp = NULL;
	path = paths(env);
	if (argc >= 5 && ft_memcmp(argv[1], "here_doc", 9) == 0)
	{
		commands = heredoc_commands(argv);
		heredoc_initialize(path, fdp, commands, argv);
	}
	if (argc >= 5)
	{
		commands = ft_commands(argv);
		initialize(path, fdp, commands, argv);
	}
}
