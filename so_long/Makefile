# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 19:17:40 by samirbouzid       #+#    #+#              #
#    Updated: 2021/08/23 14:52:01 by samirbouzid      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

SRC = srcs/*.c gnl/get_next_line.c

INC = includes/

LIBINC = libft/includes

LIB = libft.a

OBJ = main.o check_map.o utile.o get_next_line.o

CC = gcc

FLAGS = -Wall -Werror -Wextra

all	:	$(NAME)

$(NAME)	:
	make -C libft/
	$(CC) $(FLAGS) -I $(LIBINC) -I includes/ -c $(SRC)
	$(CC) $(FLAGS) $(OBJ) -L libft/ -lft -o $(NAME)

clean	:
	make clean -C libft/
	rm -f $(OBJ)

fclean	: clean
	make fclean -C libft/
	rm -f $(NAME)

re	: fclean all	




