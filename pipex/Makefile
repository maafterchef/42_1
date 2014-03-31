#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/26 16:02:55 by po-conno          #+#    #+#              #
#    Updated: 2013/12/31 20:37:51 by po-conno         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = pipex

SRC =	ft_bzero.c \
		ft_memalloc.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_path.c \
		ft_puterror.c \
		ft_read_cmd.c \
		ft_strcat.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnew.c \
		ft_strsplit.c \
		ft_strsub.c \
		check_errors.c \
		pipex.c \
		tab_management.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) -o $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAG) -c $^

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
