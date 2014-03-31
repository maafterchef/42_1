#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/15 21:16:41 by mlingels          #+#    #+#              #
#    Updated: 2014/03/31 10:04:19 by mlingels         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

SRCS = ft_ls.c\
	ft_msgs.c\
	func.c\
	func2.c\
	func3.c\
	func4.c\
	func5.c\
	func6.c\
	settings.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -o $@ $(OBJ) -L libft/ -lft

$(OBJ):
	gcc $(FLAGS) -I libft/includes/ -c $(SRCS)

clean:
	rm -rf $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all
