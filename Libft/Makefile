# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molla <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 13:40:44 by molla             #+#    #+#              #
#    Updated: 2023/02/19 18:43:41 by molla            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_toupper.c ft_tolower.c \
			ft_strncmp.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_strdup.c ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putnbr_fd.c ft_putendl_fd.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_itoa.c ft_striteri.c ft_strmapi.c ft_split.c \
			get_next_line.c get_next_line_utils.c ft_printf.c \
			ft_printf_cspercent.c ft_printf_di.c ft_printf_p.c ft_printf_u.c \
			ft_printf_xx.c ft_print.c
SRCSBONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c
HEADER		= include
OBJS		= ${SRCS:.c=.o}
OBJSBONUS	= ${SRCSBONUS:.c=.o}
NAME		= libft.a

all : ${NAME}

${NAME} : ${OBJS}
	ar rcs $@ $^

%.o : %.c ${HEADER}/libft.h ${HEADER}/get_next_line.h ${HEADER}/ft_printf.h 
	${CC} ${CFLAGS} -I${HEADER} -o $@ -c $<

clean :
	rm -f ${OBJS} ${OBJSBONUS}

fclean : clean
	rm -f ${NAME}

re : fclean all

bonus : ${OBJS} ${OBJSBONUS}
	ar rcs ${NAME} $^

.PHONY : all clean fclean re bonus
