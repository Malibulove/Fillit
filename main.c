/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:54:54 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/30 16:24:01 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	solve_driver(int fd)
{
	t_tetris	*tmp;
	t_tetris	*stack;
	int			size;
	char		**grid;

	tmp = store_tet(fd, NULL);
	size = start_size(tmp);
	stack = id_to_coord(tmp);
	stack_free(tmp);
	grid = gen_grid(size);
	while (!solve_tet(grid, stack, size))
	{
		free_grid(grid, size);
		size = size + 1;
		grid = gen_grid(size);
	}
	print_grid(grid, size);
	stack_free_coord(stack);
	return (1);
}

static int	preread(const int fd)
{
	char	*line;
	int		counter;

	line = NULL;
	counter = 0;
	while (1)
	{
		one_grid(fd, line);
		counter++;
		if (counter > 26)
		{
			close(fd);
			ft_putstr("error\n");
			return (0);
		}
		if (!get_next_line(fd, &line))
			break ;
		if (ft_strlen(line) != 0)
			return (error_handling());
	}
	close(fd);
	return (1);
}

int	error_handling(void)
{
	ft_putstr("error\n");
	return (-1);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc > 2)
		return (error_handling());
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error_handling());
	else if (fd > 0)
	{
		if (preread(fd))
		{
			fd = open(argv[1], O_RDONLY);
			solve_driver(fd);
		}
	}
	close(fd);
	return (0);
}
