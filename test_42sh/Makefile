#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/05 00:01:15 by mlingels          #+#    #+#              #
#    Updated: 2014/03/05 06:19:37 by mlingels         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 42sh

SRC = main.c\
	cursor.c\
	print.c\
	hist.c\
	tools.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAG) -o $(NAME) $(OBJ) -L /usr/lib -ltermcap -L libft/ -lft

%.o: %.c
	gcc $(FLAG) -c $^ -I ./libft/includes/

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
