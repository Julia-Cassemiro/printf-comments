# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 10:25:25 by jgomes-c          #+#    #+#              #
#    Updated: 2021/07/12 15:11:03 by jgomes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = ./
NAME	=		libft.a
SRC		=		ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_numlen.c \
				ft_strlen.c \
				ft_itoa.c \
				ft_utoa.c \
				ft_hexatoi.c \
				ft_numlen_base.c \
				ft_putnbr_base.c \
	
OBJ		=		$(SRC:%.c=%.o)

CC		=	gcc
FLAG	=	-Wall -Wextra -Werror
RM		=	rm -f

$(NAME):
	$(CC) $(FLAG) $(SRC) -c -I$(INCLUDES)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re