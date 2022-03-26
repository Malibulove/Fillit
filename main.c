/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:54:54 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/16 18:34:49 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	float	time;
	clock_t	t1;
	clock_t	t2;

	t1 = clock();
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
	t2 = clock();
	time = (float)(t2 - t1) / CLOCKS_PER_SEC;
	printf("time = %f\n", time);
}

int	solve_driver(int fd)
{
	t_tetris	*tmp;
	t_tetris	*stack;
	int			size;
	char		**grid;

	printf("start solver driver\n");
	tmp = store_tet(fd, NULL);
	size = start_size(tmp);
	stack = id_to_coord(tmp);
	stck_free(tmp);
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

int	help_solve(char **grid, int *tet, t_tetris *stack, int size)
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

int	preread(const int fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		printf("before read one\n");
		read_one(fd, line);
		printf("after read one \n");
		if (!get_next_line(fd, &line))
			break ;
		if (ft_strlen(line) != 0)
			ft_exit();
	}
	close(fd);
	return (1);
}

void	ft_exit(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}
