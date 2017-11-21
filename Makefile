# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 11:22:23 by bmuselet          #+#    #+#              #
#    Updated: 2017/11/21 18:00:00 by bmuselet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
	ft_reader.c \
	ft_checker.c \
	ft_create_list.c\
	ft_free.c\
	ft_move_tetris.c\
	ft_solver_tools.c\
	ft_solver.c\
	ft_create_list2.c\
	ft_test_pos.c\
	ft_printer.c\

OBJ = $(SRC:.c=.o)
INC = fillit.h\
	  libft.h
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB_PATH = libft/
LIB = libft/libft.a

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) :
	make re -C $(LIB_PATH)
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB) 

clean:
		make clean -C $(LIB_PATH)
		/bin/rm -f $(OBJ)

fclean: clean
		make fclean -C $(LIB_PATH)
		/bin/rm -f $(NAME)

re: fclean all

