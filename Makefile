# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 18:29:49 by ycucchi           #+#    #+#              #
#    Updated: 2022/03/23 16:55:27 by ycucchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c check_grid.c preread.c check_grid_old.c collision.c  solver.c
HEADER = fillit.h
OBJ = $(SRCS:.c=.o)
LIBFT_PATH = ./libft/
LIBFT = ./libft/libft.a
FLAGS = 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LIBFT_PATH)
	gcc $(FLAGS) -c $(SRCS)
	gcc $(OBJ) $(LIBFT) $(FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C libft/
	
fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/
	
re: fclean all
