/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kamel_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:54:21 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/06 02:44:54 by raitmous         ###   ########.fr       */
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
