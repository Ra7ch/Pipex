/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kamel_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:54:21 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/06 20:43:03 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_read(char **argv, int fd)
{
	int		i;
	char	*buf;

	i = 0;
	write(1, "pipe here_doc> ", 15);
	while (1)
	{
		buf = NULL;
		if (get_next_line(0, &buf) < 0)
			exit(1);
		if (!ft_memcmp(buf, argv[2], ft_strlen(argv[2]) + 1))
			break ;
		if (buf)
		{
			write(fd, buf, ft_strlen2(buf));
			write(fd, "\n", 1);
			write(1, "pipe here_doc> ", 15);
		}
		free(buf);
	}
	free(buf);
	close(fd);
}

void	heredoc_execute(t_array *a, int j, int fd)
{
	char	**cmd;
	int		i;

	i = 0;
	while (a->commands[++i])
		;
	if (j + 1 == i && fd < 0)
		exit(1);
	check_command(a->commands, a->path, j);
	cmd = ft_split(a->commands[j], ' ');
	execve(cmd[0], cmd, a->env);
	perror(cmd[0]);
	ft_free(cmd);
	free(cmd);
	exit(126);
}
