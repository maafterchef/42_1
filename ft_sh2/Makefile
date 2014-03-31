#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 09:58:22 by mlingels          #+#    #+#              #
#    Updated: 2014/01/26 20:50:39 by mlingels         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_minishell2

SRC = ft_sh.c\
	get_next_line.c\
	tools.c\
	run.c\
	builtin.c\
	check.c\
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
