# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 19:20:27 by ekantane          #+#    #+#              #
#    Updated: 2021/12/06 14:18:32 by ekantane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c error.c check_grid.c check_singlegrid.c
HEADER = fillit.h
OBJ = $(SRCS:.c=.o)
LIBFT_PATH = ./libft/
LIBFT = libft.a
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LIBFT_PATH)
	gcc $(FLAGS) -c $(SRC)
	gcc $(OBJ) $(LIBFT) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft/
	
fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/
	
re: fclean all