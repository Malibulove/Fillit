/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:54:19 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/04 13:11:40 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int		solve_tet(char **grid, t_tetris *stack, int size)
{
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
		grid[y][x] = c;
		i += 2;
	}
}

/* Here we print the grid by using differing letters. 'A' is used as a placeholder here, later we can use something like
tet->c so that we get some help from the struct in fillit.h. */
void	print_grid(char **grid, int *tet)
{
	int	i;
	char c;

	i = -1;
	c = 'A';
	insert_piece(grid, tet, c);
	while (grid[++i])
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
	}
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
