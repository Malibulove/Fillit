/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid_userinput.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/09 10:49:49 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int	check_grid(char **grid, int grid_count)
{
	int	x;
	int	z;
	int	y;
	int	i; // testing
	int	test; // testing
	int	count_hash;
	int	*tet;

	tet = (int *)malloc(sizeof(int) * 8);
	count_hash = 0;
	z = 0;
	x = 0 + (grid_count * 5);
	while (x < (4 + (grid_count * 5)))
	{
		y = 0;
		while (y < 4)
		{
			if (grid[x][y] != '.' && grid[x][y] != '#')
				return (-1);
			if (grid[x][y] == '#')
				{
				tet[z] = x;
				tet[z + 1] = y;
				z = z + 2;
				count_hash++;
				}
			y++;
		}
		store_tet(tet, grid_count);						//uhhhh, can we use this here :D
		if (ft_strcmp(&grid[x][y], "\0"))
			return (-1);
		x++;
		}
	z++;
	y = 0;
	if (count_hash != 4)
		return (-1);

// testing part
	i = 0;
	while (i < 8)
	{
	if (i == 0 || i == 2 || i == 4 || i == 6)
	{
		test = (tet[i] - (5 * grid_count));
		printf("%d", test);
	}
	else
		printf("%d", tet[i]);
	i++;
	}
	printf(" grid count = %d", grid_count);
	printf("\n");
// end of testing part
	return (*tet);
}


// -------------- TRANSLATING THE COORDINATES --------------------------------------------------------

int		*trans_coord(int *tet)
{
	int lx;
	int ly;
	int i;
	int size;

	size = 4;
	lx = low_x(tet);
	ly = low_y(tet);
	i = 0;
	while (size--)
	{
		tet[i] = tet[i] - lx;
		tet[i + 1] = tet[i + 1] - ly;
		i = i - 2;
	}
	return (tet);
}

int		low_x(int *tet)
{
	int x;
	int i;
	int size;

	size = 4;
	i = 0;
	x = tet[i];
	while (size--)
	{
		if (tet[i] >= 0 && tet[i] <= 3)
			if (tet[i] < x)
				x = tet[i];
		i = i - 2;
	}
	return (x);
}

int		low_y(int *tet)
{
	int y;
	int i;
	int size;

	size = 4;
	i = 1;
	y = tet[i];
	while (size--)
	{
		if (tet[i] >= 0 && tet[i] <= 3)
			if (tet[i] < y)
				y = tet[i];
		i = i - 2;
	}
	return (y);
}

// -------------- LISTING --------------------------------------------------------

t_tetris	*add_piece(void *tet_id, char tet_c)
{
	t_tetris *piece;

	piece = (t_tetris *)malloc(sizeof(t_tetris));
	piece->tet_id = tet_id;
	piece->c = tet_c;
	piece->next = NULL;
	return (piece);
}

t_tetris	*append(void *tet_id, t_tetris *head, char c)
{
	t_tetris *cursor;
	t_tetris *piece;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	piece = add_piece(tet_id, c);
	cursor->next = piece;
	return (head);
}

t_tetris	*store_tet(int *tet, int grid_count)
{
	int			*tet_translated;
	char		*tet_id;
	t_tetris	*piece;
	t_tetris	*first;
	char		c;

	c = 'A';
	first = NULL;
	tet_id = get_tetid(tet);
	while (grid_count != 0)
	{
		tet_translated = trans_coord(tet);
		if (first == NULL)
			first = add_piece(tet_id, c++);
		else
			piece = append(tet_id, first, c++);
		free(tet_translated);
		grid_count--;
	}
	return (first);
}

// -------------- FINDING THE LIBRARY EQUIVALENT OF TET (In other words: Comparing tetriminos) --------------

// 1.

char	*get_tetid(int *tet) // finds the name of the tetrimino by comparing it to the arrays in fillit.h
{
	char *name;

	name = NULL;
	(tetcmp(tet, I_PIECE_0, sizeof(tet))) && (name = "I_PIECE_0");
	(tetcmp(tet, O_PIECE_0, sizeof(tet))) && (name = "O_PIECE_0");
	// etc
	return (name);
}

int	tetcmp(int *tet, int *libtet, int n) // (user input tet, pre-made tet, the size of the user input tet)
{
	int i;

	i = 0;
	while (i <= n)
	{
		if (tet[i] != libtet[i])
			return (-1);
		i++;
	}
	return (1);
}

// 2.

int		*convert_id(char *name) // converts the name back into and actual tetrimino
{
	int *tet;

	tet = (int *)malloc(sizeof(int) * 8);
	(ft_strcmp(name, "I_PIECE_0") == 0) && (dup_coord(tet, I_PIECE_0));
	(ft_strcmp(name, "O_PIECE_0") == 0) && (dup_coord(tet, O_PIECE_0));
	// etc
	return (tet);
}

int		dup_coord(int *dst, int *src)
{
	int *pdst;
	int i;

	i = 0;
	pdst = dst;
	while (i < 8)
	{
		pdst[i] = src[i];
		i++;
	}
	return (1);
}
