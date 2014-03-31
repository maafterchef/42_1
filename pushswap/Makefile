#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/27 15:49:46 by mlingels          #+#    #+#              #
#    Updated: 2013/12/27 16:24:32 by mlingels         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap

SRC = list.c\
	pushswap.c\
	tools.c\
	op.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $(OBJ)

%.o: %.c
	gcc $(FLAGS) -c $^

clean:
	/bin/rm $(OBJ)

fclean: clean
	/bin/rm $(NAME)

re: fclean all
