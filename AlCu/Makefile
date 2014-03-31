#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/07 20:30:07 by mlingels          #+#    #+#              #
#    Updated: 2014/03/09 14:38:50 by mlingels         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = puissance4

SRC = main.c\
	errors.c\
	play.c\
	grid.c\
	print.c\
	winner.c\
	get_next_line.c\
	value.c\
	values.c\
	computer.c\
	free.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cc $(FLAG) -o $(NAME) $(OBJ) -L libft/ -lft

%.o: %.c
	cc $(FLAG) -c $^ -I ./libft/includes/

clean:
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean re fclean
