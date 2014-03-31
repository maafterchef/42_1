#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 10:10:40 by mlingels          #+#    #+#              #
#    Updated: 2013/12/22 18:57:16 by mlingels         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = ft_printf.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putstr.c\
	ft_strlen.c\
	ft_check.c\
	ft_check_2.c\
	ft_putunbr.c\
	ft_putoct.c\
	ft_puthex.c\
	ft_putptr.c\
	ft_atoi.c\
	ft_opt.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^ ; ranlib $(NAME)

%.o: %.c
	gcc -o $@ -I includes/ -c $(FLAGS) $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
