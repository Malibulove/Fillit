/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:54:19 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/01 16:31:21 by ycucchi          ###   ########.fr       */
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
//				reset_y(tet, size);
				if (collision(grid, tet, size) == 1)
				{
					printf("collision\n");
//					reset_y(tet, size);
//					reset_x(tet, size);
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

int		*reset_y(int *tet, int size)
{
	int i;

	i = 1;
	while (size--)
	{
		tet[i] = 0;
		i += 2;
	}
	return (tet);
}

int		*reset_x(int *tet, int size)
{
	int i;

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
