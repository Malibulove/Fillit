/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:54:19 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/01 23:37:20 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int		solve_tet(char **grid, int *tet, int size)
{
	int x;
	int y;
/*
comment the function here :
if collision = 1 ==> collision
if collision = 0 ==> pas de collision
we want to check first by incresing Ys
if it's not enough, reset Ys (we can't just reset everything to 0)
then we increase x by 1 and we try again threw all Ys
we go threw all Xs and Ys and IF it's not enough we will increase size by 1
after that we can start the all process again until we don't have any collision
(from grid/piece)
we will need to change shift_tet because if size is bigger than 4, i will be
bigger than 8
*/
	int *temp;
	temp = (int *)malloc(sizeof(int) * 8);
	*temp = dup_coord(temp, tet);
	if (collision(grid, tet, size) == 1)
	{
		printf("there's a collision, we need to move tetriminos\n");
		x = 0;
		printf("size = %d\n", size);
		while (x < size)
		{
			reset_y(tet, size, y);
			printf("x = %d\n", x);
			y = 0;
			while (y < size)
			{
				printf("y = %d\n", y);
//				shift_tet(tet, x, y);
//				reset_y(tet, size, y);
				if (box_collision(tet, size) == -1)
				{
					printf("box collision, we need to reset Ys\n");
					reset_y(tet, size, y);
//					reset_x(tet, size, x);
				}
				if (collision(grid, tet, size) == 0)
					printf("==> NO COLLISION <==\n");
				shift_tet(tet, x, y);
				reset_x(tet, size, x);
				y++;
			}
			x++;
		}
//		size++;
	}
	free(tet);
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
	y = y + 0;
	size = 4;
	i = 1;
	while (size--)
	{
		tet[i] = tet[i] + 1;
		i += 2;
	}
	return (tet);
}

int		*reset_y(int *tet, int size, int y)
{
	int i;

	i = 1;
	printf("y inside reset y = %d\n", y);
	while (size--)
	{
		tet[i] = tet[i] - y;
		i += 2;
	}
	return (tet);
}

int		*reset_x(int *tet, int size, int x)
{
	int i;

	i = 0;
	while (size--)
	{
		tet[i] = tet[i] - x;
		i +=2;
	}
	return(tet);
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
