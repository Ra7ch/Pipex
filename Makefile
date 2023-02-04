# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 21:13:00 by raitmous          #+#    #+#              #
#    Updated: 2023/02/04 23:41:17 by raitmous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c pipex_paths.c pipex_utils.c
SRCS_BONUS = bonus/main_bonus.c bonus/pipex_paths_bonus.c bonus/kamel_functions.c bonus/pipex_utils_bonus.c bonus/pipex_heredoc_utils.c
OBJS	= ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
NAME	= pipex
LIBFT	= Libft/libft.a

all	: ${LIBFT} ${NAME}

${NAME} : ${OBJS}
	cc ${CFLAGS} ${SRCS} ${LIBFT} -o ${NAME}


	

${LIBFT}:
			make bonus -C ./Libft

bonus : ${LIBFT} ${OBJS_BONUS}
		cc ${CFLAGS} ${SRCS_BONUS} ${LIBFT} -o ${NAME}
clean :
	${RM} ${OBJS} ${OBJS_BONUS}
	make clean -C ./Libft

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}
	make fclean -C ./Libft

re : fclean all

a : all clean

b : bonus clean