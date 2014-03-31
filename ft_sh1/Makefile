#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 16:12:15 by mlingels          #+#    #+#              #
#    Updated: 2013/12/27 19:22:32 by mlingels         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_minishell1

SRCS = minishell.c\
	get_next_line.c\
	tools.c\
	builtin.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -o $@ $(OBJ) -L libft/ -lft

%.o: %.c
	gcc $(FLAGS) -I libft/includes/ -c $^

clean:
	/bin/rm -rf $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all
