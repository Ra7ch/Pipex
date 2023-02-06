/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:06:57 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/06 04:09:51 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(t_array *a, int j)
{
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(a->commands[j], ' ');
	execve(cmd[0], cmd, a->env);
	perror(cmd[0]);
	ft_free(cmd);
	free(cmd);
	exit(126);
}

int	ft_fork(t_array *a, int **fdp, int j)
{
	int	pid;
	int	i;

	i = 0;
	while (a->commands[++i])
		;
	pid = fork();
	if (pid == 0)
	{
		if (j + 1 == i && fdp[0][1] < 0)
			exit(1);
		check_command(a->commands, a->path, j);
		close(fdp[j + 1][0]);
		if (fdp[j][0] == -1)
			exit(0);
		dup2(fdp[j][0], 0);
		if (j + 1 != i)
			dup2(fdp[j + 1][1], 1);
		else
			dup2(fdp[0][1], 1);
		execute(a, j);
	}
	close(fdp[j][0]);
	close(fdp[j + 1][1]);
	return (pid);
}

void	ft_status(int *pid, int j, int **fdp)
{
	int	i;
	int	status;

	i = 1;
	close(fdp[0][1]);
	while (i < j)
		i++;
	i--;
	waitpid(pid[i], &status, 0);
	i--;
	while (i >= 0)
	{
		waitpid(pid[i], 0, 0);
		i--;
	}
	free(pid);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else
		exit(1);
}

void	initialize(int **fdp, t_array *a)
{
	int	j;
	int	i;
	int	*pid;

	i = 0;
	while (a->commands[i])
		i++;
	fdp = malloc((i + 1) * sizeof(int *));
	pid = malloc(i * sizeof(int));
	fdp[0] = fd_files(a->argv);
	j = 0;
	while (j + 1 <= i)
	{
		fdp[j + 1] = malloc(2 * sizeof(int));
		pipe(fdp[j + 1]);
		pid[j] = ft_fork(a, fdp, j);
		j++;
	}
	ft_status(pid, j, fdp);
}

int	main(int argc, char **argv, char **env)
{
	int		**fdp;
	t_array	a;

	a.argv = argv;
	a.env = env;
	fdp = NULL;
	if (argc == 5)
	{
		a.path = paths(env);
		a.commands = ft_commands(argv);
		initialize(fdp, &a);
	}
	else
	{
		write(1, "Check your arguments count.\n", 29);
		exit(1);
	}
}
