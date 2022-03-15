/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:54:54 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/14 12:54:49 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;

	if (argc > 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	else if (fd > 0)
	{
		printf("before check grid\n");
		if (preread(fd))
		{
			fd = open(argv[1], O_RDONLY);
			solve_driver(fd);
		}
	}
	close(fd);
}

	int		solve_driver(int fd)
{
	t_tetris	*tmp;
	t_tetris	*stack;
	int			size;
	char		**grid;
	printf("start solver driver\n");
	tmp = store_tet(fd, NULL);
//	size = start_size(tmp);
	size = 4;
	stack = id_to_coord(tmp);
	stck_free(tmp);
	printf("tmp freed\n");
	grid = gen_grid(size);
	printf("after grid_size\n");
		while (!solve_tet(grid, stack, size))
	{
		printf("inside the while to increase size\n");
		free_grid(grid, size);
		size = size + 1;
		printf("size is now = %d\n", size);
		grid = gen_grid(size);
	}
	printf("before print grid\n");
	print_grid(grid, size);
	stck_free_coord(stack);
	printf("end of check_grid\n");
	return (1);
}

int		help_solve(char **grid, int *tet, t_tetris *stack, int size)
{
	if (collision(grid, tet, size))
	{
		insert_piece(grid, tet, stack->c);
		if (solve_tet(grid, stack->next, size))
		{
			free(tet);
			return (1);
		}
		clear_piece(grid, tet);
	}
	return (0);
}
