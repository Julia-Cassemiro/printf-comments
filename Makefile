# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 10:25:25 by jgomes-c          #+#    #+#              #
#    Updated: 2021/07/12 15:18:28 by jgomes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libftprintf.a
SRC_PATH	=		src/

LIBFT_PATH	=		libft/

LIBFT_LIB	=		libft.a

SRC_FILES	= \
	./src/brprint.c \
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

SRC_OBJS     = ${SRC_FILES:.c=.o}

CC         = gcc

CFLAGS         = -Wall -Wextra -Werror

RM         = rm -f

AR         = ar crs

LIBFT_OBJS    = ${LIBFT_PATH}*.o

LIBFTMAKE    = $(MAKE) -C ${LIBFT_PATH}

all:				${NAME}

${NAME}:    ${SRC_OBJS} pmake
			${AR} ${NAME} ${SRC_OBJS} ${LIBFT_OBJS}

pmake:
			${LIBFTMAKE}

clean:
			make -C ${LIBFT_PATH} clean
			${RM} ${SRC_OBJS}

fclean: 	clean
			${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:         fclean all

.PHONY:        all clean fclean re