# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 10:25:25 by jgomes-c          #+#    #+#              #
#    Updated: 2021/07/17 14:04:26 by jgomes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libftprintf.a
SRC_PATH	=		src/

LIBFT_PATH	=		libft/

LIBFT_LIB	=		${LIBFT_PATH}libft.a

SRC_FILES	= \
	./src/ftprintf.c \
	./src/ft_verific.c \
	./src/ft_maybe.c \
	./src/to_char.c \
	./src/to_string.c \
	./src/to_hexa.c \
	./src/to_int.c \
	./src/to_percentage.c \
	./src/to_unsigned.c \
	./src/to_point.c \
	./src/ft_lenght.c \
	./src/ft_zero.c \

SRC_OBJS     = ${SRC_FILES:.c=.o}

CC         = gcc

CFLAGS		= -Wall -Wextra -Werror

RM         = rm -f

AR         = ar cr

LIBFT_OBJS    = ${LIBFT_PATH}


all:				${NAME}

${NAME}:    ${SRC_OBJS}
			make -C ${LIBFT_PATH}
			cp ${LIBFT_LIB} ${NAME}
			mv ${LIBFT_LIB} ${NAME}
			${AR} ${NAME} ${SRC_OBJS}

bonus: all

clean:
			make -C ${LIBFT_PATH} clean
			${RM} ${SRC_OBJS}

fclean: 	clean
			${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:         fclean all

.PHONY:        all clean fclean re