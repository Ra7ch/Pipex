/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:07:26 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/07 00:34:20 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include "bonus/get_next_line.h"
# include "fcntl.h"
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
int			check_access(char *cmd);
void		if_its_command(char *cmd, char **s, char **paths);

#endif
