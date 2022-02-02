# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 19:20:27 by ekantane          #+#    #+#              #
#    Updated: 2022/02/02 16:40:07 by ycucchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c check_grid.c
HEADER = fillit.h
OBJ = $(SRCS:.c=.o)
LIBFT_PATH = ./libft/
LIBFT = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

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
