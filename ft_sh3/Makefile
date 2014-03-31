#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/29 11:03:32 by mlingels          #+#    #+#              #
#    Updated: 2014/01/31 16:06:43 by mlingels         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_minishell3

SRC = ft_sh.c\
	get_next_line.c\
	tools.c\
	run.c\
	builtin.c\
	check.c\
	list.c\
	keys.c\
	ft_cd.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAG) -o $(NAME) $(OBJ) -L /usr/lib -ltermcap -L libft/ -lft

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
