/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:54:19 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/10 11:35:40 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int		solve_tet(char **grid, t_tetris *stack, int size)
{
	int		x;
	int		y;
	int		*tet;

	y = -1;
	tet = (int *)malloc(sizeof(int) * 8);
	if (!stack)
	{
		free(tet);
		return (1);
	}
	while (++y < size)
	{
		x = -1;
		printf("y = %d\n", y);
		while (++x < size)
		{
			printf("x = %d\n", x);
			dup_coord(tet, stack->tet_id);
			shift_tet(tet, x ,y);
			if (help_solve(grid, tet, stack, size))
				return (1);
		}
	}
	free(tet);
	return (0);
}

int		help_solve(char **grid, int *tet, t_tetris *stack, int size)
{
	if (collision(grid, tet, size))
	{
		printf("collision = %d\n", collision(grid, tet, size));
		insert_piece(grid, tet, stack->c);
		if (solve_tet(grid, stack->next, size))
		{
			printf("after solve_tet");
			free(tet);
			return (1);
		}
		clear_piece(grid, tet);
	}
	return (0);
}

/* Here we include the tet being handled as part of the first grid. */
void	insert_piece(char **grid, int *tet, char c)
{
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	while (i < 8)
	{
		y = tet[i + 1];
		x = tet[i];
		grid[x][y] = c;
		i += 2;
	}
	printf("piece inserted\n");
}

void	clear_piece(char **grid, int *tet)
{
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	while (i < 8)
	{
		y = tet[i + 1];
		x = tet[i];
		grid[y][x] = '.';
		i += 2;
	}
}

/* Here we print the grid by using differing letters. 'A' is used as a placeholder here, later we can use something like
tet->c so that we get some help from the struct in fillit.h */
void	print_grid(char **grid, int *tet, int size)
{
	int	i;
	int *test;

	test = tet;
	i = -1;
	while (grid[++i])
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
	}
	free_grid(grid, size);
}

/* This and the following function move the tetriminos maximum as many ticks as there are space. */
int		*x_shift(int *tet, int x)
{
	int i;
	int size;

	size = 4;
	i = 0;
	while (size--)
	{
		tet[i] = tet[i] + x;
		i += 2;
	}
	return (tet);
}

int		*y_shift(int *tet, int y)
{
	int i;
	int size;

	size = 4;
	i = 1;
	while (size--)
	{
		tet[i] = tet[i] + y;
		i += 2;
	}
	return (tet);
}

/* This function serves as a port combining x and y shifting. */
int		*shift_tet(int *tet, int x, int y)
{
	int	i;

	i = 0;
	tet = x_shift(tet, x);
	tet = y_shift(tet, y);
	printf("tet after shift = ");
	while (i < 8)
	{
		printf("%d", tet[i]);
		i++;
	}
	printf("\n");
	return (tet);
}

int		start_size(t_tetris *stack)
{
	int		blocks;
	int		size;

	size = 2;
	blocks = (count_tet(stack) * 4);
	while (blocks > (size * size))
		size += 1;
	return (size);
}

char	*gen_line(int col)
{
	char	*line;
	int		i;

	i = 0;
	if (!(line = (char *)malloc(sizeof(char) * col + 1)))
		return (NULL);
	while (i < col)
	{
		line[i] = '.';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**gen_grid(int size)
{
	char	**grid;
	int		i;
	char	*line;

	i = 0;
	if (!(grid = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (i < size)
	{
		grid[i] = (char *)malloc(sizeof(char) * size + 1);
		line = gen_line(size);
		ft_strcpy(grid[i], line);
		free(line);
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

int			count_tet(t_tetris *stack)
{
	int			c;
	t_tetris	*tmp;

	tmp = stack;
	c = 0;
	while (tmp)
	{
		c++;
		tmp = tmp->next;
	}
	return (c);
}

void	stck_free(t_tetris *stack)
{
	t_tetris *tmp;

	tmp = NULL;
	while (stack)
	{
		tmp = stack;
		stack = tmp->next;
		free(tmp);
	}
}

void	stck_free_coord(t_tetris *stack)
{
	t_tetris *tmp;

	tmp = NULL;
	while (stack)
	{
		tmp = stack;
		stack = tmp->next;
		free(tmp->tet_id);
		free(tmp);
	}
}

void	free_grid(char **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&grid[i]);
		i++;
	}
	free(grid);
}
