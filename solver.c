/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:54:19 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/01 16:03:47 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

/*
t_tetris	stack_tet(void *tet_id, t_tetris *head, char c)
{
	t_tetris	*cursor;
	t_tetris	*piece;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	piece = add_piece(tet_id, c);
	cursor->next = piece;
	return (head);
}

	while (cursor->next != NULL)			// use something like this loop
	{
		
		cursor = cursor->next;
	}
*/

int		solve_tet(char **grid, int *tet, int size)
{
	int x;
	int y;
// if collision = 1 ==> collision
// if collision = 0 ==> pas de collision
	printf("size = %d\n", size);
	if (collision(grid, tet, size) == 1)
	{
		x = 0;
		printf("size = %d\n", size);
		while (x < size)
		{
			printf("x = %d\n", x);
			y = 0;
			while (y < size)
			{
				printf("y = %d\n", y);
				shift_tet(tet, x, y);
				reset_y(tet);
				if (collision(grid, tet, size) == 1)
				{
					printf("collision\n");
					reset_y(tet);
					reset_x(tet);
				}
				if (collision(grid, tet, size) == 0)
					printf("==> NO COLLISION <==\n");
				y++;
			}
			x++;
		}
		size++;
	}
	free(tet);
	return (0);
}

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

int		*reset_y(int *tet)
{
	int i;
	int size;

	size = 4;
	i = 1;
	while (size--)
	{
		tet[i] = 0;
		i += 2;
	}
	return (tet);
}

int		*reset_x(int *tet)
{
	int i;
	int size;

	size = 4;
	i = 1;
	while (size--)
	{
		tet[i] = 0;
		i +=2;
	}
	return(tet);
}

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
