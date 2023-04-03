# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molla <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 10:19:56 by molla             #+#    #+#              #
#    Updated: 2023/03/31 11:23:38 by molla            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= Libft/
SRCS		= pipex.c
OBJS		= ${SRCS:.c=.o}
NAME		= pipex

all : ${NAME}

${NAME} : ${OBJS}
	${MAKE} -C ${LIBFT}
	${CC} ${CFLAGS} $^ ${LIBFT}libft.a -o $@

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm -f ${OBJS}
	${MAKE} clean -C ${LIBFT}

fclean : clean
	rm -f ${NAME}
	${MAKE} fclean -C ${LIBFT}

re : fclean all

.PHONY : all clean fclean re