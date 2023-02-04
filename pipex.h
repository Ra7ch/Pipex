/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:07:26 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/03 20:48:38 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
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

#endif