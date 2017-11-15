# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 11:22:23 by bmuselet          #+#    #+#              #
#    Updated: 2017/11/15 12:43:59 by bmuselet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
	ft_reader.c \
	checker.c \
	ft_create_elem.c\
#	solver.c \
#	printer.c
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB) 

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

