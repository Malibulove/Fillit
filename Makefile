# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 18:29:49 by ycucchi           #+#    #+#              #
#    Updated: 2022/04/01 15:36:12 by ycucchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c check_grid.c coord_swap.c stack.c collision.c free.c solver.c \
identification.c initialization.c grid.c grid_utils.c \
tet_making.c tet_making2.c tet_making3.c tet_making4.c
HEADER = fillit.h
OBJ = $(SRCS:.c=.o)
LIBFT_PATH = ./libft/
LIBFT = ./libft/libft.a
FLAGS = -Wall -Wextra #-fsanitize=address #-Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LIBFT_PATH)
	gcc $(FLAGS) -c $(SRCS)
	gcc $(OBJ) $(LIBFT) $(FLAGS) -o $(NAME)

debug:
	gcc -g $(FLAGS) -I . libft/libft.a $(SRCS) -o debug

clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/
	rm -rf debug.dSYM
	rm -rf debug

re: fclean all
