#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 22:02:20 by mlingels          #+#    #+#              #
#    Updated: 2014/02/08 16:26:28 by rnicolas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_SERV = serveur

NAME_CL = client

SRC_SERV = serv.c

SRC_CL = client.c

OBJ_SERV = $(SRC_SERV:.c=.o)

OBJ_CL = $(SRC_CL:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME_SERV) $(NAME_CL)

$(NAME_SERV): $(OBJ_SERV) 
	make -C libft
	gcc -g $(FLAG) -o $(NAME_SERV) $(OBJ_SERV) -L libft/ -lft

$(NAME_CL): $(OBJ_CL)
	make -C libft
	gcc -g $(FLAG) -o $(NAME_CL) $(OBJ_CL) -L libft/ -lft

%.o: %.c
	gcc -g $(FLAG) -c $^ -I ./libft/includes/

clean:
	/bin/rm -f $(OBJ_SERV)
	/bin/rm -f $(OBJ_CL)
	make clean -C libft/

fclean:
	/bin/rm -f $(OBJ_SERV)
	/bin/rm -f $(OBJ_CL)
	/bin/rm -f $(NAME_SERV)
	/bin/rm -f $(NAME_CL)
	make fclean -C libft/

re: fclean all

.PHONY: all clean re fclean
