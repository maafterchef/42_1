#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 09:58:22 by mlingels          #+#    #+#              #
#    Updated: 2014/01/26 20:51:21 by mlingels         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler

SRC = filler.c\
	get_next_line.c\
	place.c\
	try.c\
	free.c


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
