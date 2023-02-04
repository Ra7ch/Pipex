/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:09:09 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/03 22:27:08 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

int	*fd_files(char **argv)
{
	int	i;
	int	*fd;

	i = 1;
	fd = malloc(2 * 4);
	fd[0] = open(argv[1], O_RDONLY);
	while (argv[i + 1])
		i++;
	fd[1] = open(argv[i], O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (fd[0] == -1)
		perror(argv[1]);
	if (fd[1] == -1)
		(perror(argv[i]), exit(1));
	return (fd);
}

char	**ft_commands(char **argv)
{
	int		i;
	int		j;
	char	**commands;

	i = 2;
	while (argv[i + 2])
		i++;
	commands = malloc(i * sizeof(char *));
	j = 0;
	while (j <= i - 2)
	{
		commands[j] = argv[j + 2];
		j++;
	}
	commands[j] = NULL;
	return (commands);
}

static int	check_command_path(char **commands, char **paths, char **cmd, int k)
{
	int		j;
	char	*path;

	j = 0;
	while (paths[j])
	{
		path = ft_strjoin(paths[j], cmd[0]);
		if (access(path, F_OK) == 0)
		{
			free(path);
			ft_free(cmd);
			commands[k] = ft_strjoin(paths[j], commands[k]);
			break ;
		}
		free(path);
		j++;
	}
	return (j);
}

void	check_command(char **commands, char **paths, int k)
{
	int		j;
	char	**cmd;

	cmd = ft_split(commands[k], ' ');
	if (access(cmd[0], F_OK) == -1)
	{
		j = check_command_path(commands, paths, cmd, k);
		if (paths[j] == NULL)
		{
			ft_free(cmd);
			free(cmd);
			ft_free(paths);
			ft_putstr_fd(commands[k], 2);
			ft_putstr_fd(": Command not found\n", 2);
			exit(127);
		}
	}
	free(cmd);
	ft_free(paths);
}
