/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:07:26 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/04 22:56:40 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/libft.h"
# include "fcntl.h"
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "unistd.h"
# include <sys/wait.h>

char	**paths(char **env);
int		*fd_files(char **argv);
void	ft_free(char **str);
char	**ft_commands(char **argv);
void	check_command(char **commands, char **paths, int k);
char	**heredoc_commands(char **argv);

void	heredoc_initialize(char **path, int **fdp, char **commands,
			char **argv);
void	ft_status(int *pid, int j, int **fdp);
int		ft_fork(char **commands, int **fdp, char **paths, int j);
void	execute(char **commands, int j);
char	*ft_kamel(int fd, char **argv);

#endif