/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:51:32 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/04 23:47:46 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**heredoc_commands(char **argv)
{
	int		i;
	int		j;
	char	**commands;

	i = 3;
	while (argv[i + 2])
		i++;
	commands = malloc((i) * sizeof(char *));
	j = 0;
	while (j <= i - 3)
	{
		commands[j] = argv[j + 3];
		j++;
	}
	commands[j] = NULL;
	return (commands);
}

int	heredoc_fork(char **commands, int **fdp, char **paths, int j)
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
		if (j && j + 1 == i)
			close(fdp[j][1]);
		if (fdp[j][0] == -1)
			exit(0);
		dup2(fdp[j][0], 0);
		if (j + 1 != i)
			dup2(fdp[j + 1][1], 1);
		else
			dup2(fdp[i + 1][0], 1);
		execute(commands, j);
	}
	close(fdp[j][0]);
	close(fdp[j + 1][1]);
	return (pid);
}

void	heredoc_fd_files(char **argv, int **fdp, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		fdp[j] = malloc(2 * sizeof(int));
		pipe(fdp[j]);
		j++;
	}
	fdp[j] = malloc(2 * sizeof(int));
	fdp[j][0] = open(argv[i + 3], O_WRONLY | O_CREAT | O_APPEND, 0644);
}

void	heredoc_status(int *pid, int j, int **fdp)
{
	int	i;
	int	status;

	i = 0;
	close(fdp[0][0]);
	close(fdp[0][1]);
	close(fdp[i + 1][0]);
	while (i < j)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	free(pid);
	exit(WEXITSTATUS(status));
}

void	heredoc_initialize(char **path, int **fdp, char **commands, char **argv)
{
	int		j;
	int		i;
	int		*pid;
	char	*s;

	i = 0;
	while (commands[i])
		i++;
	fdp = malloc((i + 2) * sizeof(int *));
	pid = malloc(i * sizeof(int));
	heredoc_fd_files(argv, fdp, i);
	s = ft_kamel(0, argv);
	j = 0;
	if (j == 0)
		(ft_putstr_fd(s, fdp[0][1]), close(fdp[0][1]), free(s));
	while (j + 1 <= i)
	{
		pid[j] = heredoc_fork(commands, fdp, path, j);
		j++;
	}
	heredoc_status(pid, j, fdp);
}
