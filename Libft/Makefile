# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raitmous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 23:41:55 by raitmous          #+#    #+#              #
#    Updated: 2022/10/24 23:47:56 by raitmous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c ft_isprint.c ft_strrchr.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strtrim.c ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c	ft_substr.c ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_tolower.c ft_isalpha.c ft_memcpy.c ft_split.c ft_strlen.c ft_toupper.c ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_BONUS = ${BONUS_SRCS:.c=.o}
OBJS	= ${SRCS:.c=.o}
CFLAGS	= -Wall -Wextra -Werror
CC		= cc
AR		= ar rc
RM		= rm -rf
NAME	= libft.a
RANLIB	= ranlib

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
	${RANLIB} ${NAME}

bonus: ${OBJS_BONUS} all
	${AR} ${NAME} ${OBJS_BONUS}
	${RANLIB} ${NAME}
clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all
