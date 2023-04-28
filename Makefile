# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molla <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 10:19:56 by molla             #+#    #+#              #
#    Updated: 2023/04/24 17:38:02 by molla            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= Libft/
SRCS		= pipex.c utils.c
SRCSBONUS	= bonus/pipex_bonus.c bonus/utils_bonus.c
OBJS		= ${SRCS:.c=.o}
OBJSBONUS	= ${SRCSBONUS:.c=.o}
NAME		= pipex

all : ${NAME}

${NAME} : ${OBJS}
	${MAKE} -C ${LIBFT}
	${CC} ${CFLAGS} $^ ${LIBFT}libft.a -o $@

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm -f ${OBJS} ${OBJSBONUS}
	${MAKE} clean -C ${LIBFT}

fclean : clean
	rm -f ${NAME}
	${MAKE} fclean -C ${LIBFT}

re : fclean all

bonus : ${OBJSBONUS}
	${MAKE} -C ${LIBFT}
	${CC} ${CFLAGS} $^ ${LIBFT}libft.a -o ${NAME}

.PHONY : all clean fclean re