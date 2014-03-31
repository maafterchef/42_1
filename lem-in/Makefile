#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/21 14:37:18 by mlingels          #+#    #+#              #
#    Updated: 2014/02/21 16:25:19 by mlingels         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

SRC = main.c\
	hill.c\
	room.c\
	list.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAG) -o $(NAME) $(OBJ) -L libft/ -lft

%.o: %.c
	gcc $(FLAG) -c $^ -I ./libft/includes/

clean:
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean re fclean
