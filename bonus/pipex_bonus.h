/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:07:26 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/06 20:52:06 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/libft.h"
# include "fcntl.h"
# include "get_next_line.h"
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "unistd.h"
# include <sys/wait.h>

typedef struct s_array
{
	char	**argv;
	char	**env;
	char	**path;
	char	**commands;
}			t_array;

char		**paths(char **env);
int			*fd_files(char **argv);
void		ft_free(char **str);
char		**ft_commands(char **argv);
void		check_command(char **commands, char **paths, int k);
char		**heredoc_commands(char **argv);
void		heredoc_initialize(t_array *a, int **fdp);
void		ft_status(int *pid, int j, int **fdp);
void		execute(t_array *a, int j);
void		ft_read(char **argv, int fd);
int			check_access(char *cmd);
void		if_its_command(char *cmd, char **s, char **paths);
void		heredoc_execute(t_array *a, int j, int fd);

#endif