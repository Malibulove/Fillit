/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/14 17:57:37 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int	check_grid(char **grid, int grid_count, int i)
{
	int	x;
	int	z;
	int	y;
	int	count_hash;
	int	*tet;

	tet = (int *)malloc(sizeof(int) * 8);
	count_hash = 0;
	if (!tet)
		printf("malloc error");
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
		if (ft_strcmp(&grid[x][y], "\0"))
			return (-1);
		x++;
	}
	z++;
	y = 0;
	error_check(grid, count_hash, i, x, y);
	print_tet(tet, grid_count);
	store_tet(tet, grid_count);
	return (*tet);
}

int	error_check(char **grid, int count_hash, int i, int x, int y)
{
	if (&grid[x][y] == NULL && i == 4)
	{
		if (count_hash != 4)
			return (-1);
	}
	else if (count_hash != 4 || ft_strcmp(&grid[x][y], "\0"))
		return (-1);
	return (1);
}

int	*print_tet(int *tet, int grid_count)
{
	int	j;
	int	test;
	int	first_grid[8] = {0, 0, 1, 0, 1, 1, 2, 1};

	j = 0;
	while (j < 8)
	{
		if (j == 0 || j == 2 || j == 4 || j == 6)
		{
			test = (tet[j] - (5 * grid_count));
			printf("%d", test);
		}
		else
			printf("%d", tet[j]);
		j++;
	}
	printf(" grid count = %d", grid_count);
	printf("\n");
	if (piece_collision(first_grid, tet) == 1)		// testing collision
			printf("the pieces collide\n");			// testing collision
	if (piece_collision(first_grid, tet) == -1)		// testing collision
			printf("the pieces do not collide\n");	// testing collision
	return (tet);
}

// -------------- TRANSLATING THE COORDINATES --------------------------------------------------------

int		*trans_coord(int *tet)
{
	int	lx;
	int	ly;
	int	i;
	int	size;

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
	int	x;
	int	i;
	int	size;

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
	int	y;
	int	i;
	int	size;

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
	t_tetris	*piece;

	piece = (t_tetris *)malloc(sizeof(t_tetris));
	piece->tet_id = tet_id;
	piece->c = tet_c;
	piece->next = NULL;
	return (piece);
}

t_tetris	*append(void *tet_id, t_tetris *head, char c)
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
		if (!(tet_id = get_tetid(tet)))
			exit(EXIT_FAILURE);
		if (first == NULL)
			first = add_piece(tet_id, c++);
		else
			piece = append(tet_id, first, c++);
		grid_count--;
	}
	return (first);
}

// -------------- FINDING THE LIBRARY EQUIVALENT OF TET (In other words: Comparing tetriminos) --------------

// 1.

char	*get_tetid(int *tet) // finds the name of the tetrimino by comparing it to the arrays in fillit.h
{
	char	*name;

	name = NULL;
	(tetcmp(tet, I_PIECE, sizeof(tet))) && (name = "I_PIECE");
	(tetcmp(tet, IH_PIECE, sizeof(tet))) && (name = "IH_PIECE");
	(tetcmp(tet, O_PIECE, sizeof(tet))) && (name = "O_PIECE");
	(tetcmp(tet, L_PIECE, sizeof(tet))) && (name = "L_PIECE");
	(tetcmp(tet, LR_PIECE, sizeof(tet))) && (name = "LR_PIECE");
	(tetcmp(tet, LD_PIECE, sizeof(tet))) && (name = "LD_PIECE");
	(tetcmp(tet, LL_PIECE, sizeof(tet))) && (name = "LL_PIECE");
	(tetcmp(tet, J_PIECE, sizeof(tet))) && (name = "J_PIECE");
	(tetcmp(tet, JR_PIECE, sizeof(tet))) && (name = "JR_PIECE");
	(tetcmp(tet, JD_PIECE, sizeof(tet))) && (name = "JD_PIECE");
	(tetcmp(tet, JL_PIECE, sizeof(tet))) && (name = "JL_PIECE");
	(tetcmp(tet, T_PIECE, sizeof(tet))) && (name = "T_PIECE");
	(tetcmp(tet, TR_PIECE, sizeof(tet))) && (name = "TR_PIECE");
	(tetcmp(tet, TD_PIECE, sizeof(tet))) && (name = "TD_PIECE");
	(tetcmp(tet, TL_PIECE, sizeof(tet))) && (name = "TL_PIECE");
	(tetcmp(tet, S_PIECE, sizeof(tet))) && (name = "S_PIECE");
	(tetcmp(tet, SR_PIECE, sizeof(tet))) && (name = "SR_PIECE");
	(tetcmp(tet, Z_PIECE, sizeof(tet))) && (name = "Z_PIECE");
	(tetcmp(tet, ZR_PIECE, sizeof(tet))) && (name = "ZR_PIECE");
	return (name);
}

int	tetcmp(int *tet, int *libtet, int n) // (user input tet, pre-made tet, the size of the user input tet)
{
	int	i;

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
	int	*tet;

	tet = (int *)malloc(sizeof(int) * 8);
	(ft_strcmp(name, "I_PIECE") == 0) && (dup_coord(tet, I_PIECE));
	(ft_strcmp(name, "IH_PIECE") == 0) && (dup_coord(tet, IH_PIECE));
	(ft_strcmp(name, "O_PIECE") == 0) && (dup_coord(tet, O_PIECE));
	(ft_strcmp(name, "L_PIECE") == 0) && (dup_coord(tet, L_PIECE));
	(ft_strcmp(name, "LR_PIECE") == 0) && (dup_coord(tet, LR_PIECE));
	(ft_strcmp(name, "LD_PIECE") == 0) && (dup_coord(tet, LD_PIECE));
	(ft_strcmp(name, "LL_PIECE") == 0) && (dup_coord(tet, LL_PIECE));
	(ft_strcmp(name, "J_PIECE") == 0) && (dup_coord(tet, J_PIECE));
	(ft_strcmp(name, "JR_PIECE") == 0) && (dup_coord(tet, JR_PIECE));
	(ft_strcmp(name, "JD_PIECE") == 0) && (dup_coord(tet, JD_PIECE));
	(ft_strcmp(name, "JL_PIECE") == 0) && (dup_coord(tet, JL_PIECE));
	(ft_strcmp(name, "T_PIECE") == 0) && (dup_coord(tet, T_PIECE));
	(ft_strcmp(name, "TR_PIECE") == 0) && (dup_coord(tet, TR_PIECE));
	(ft_strcmp(name, "TD_PIECE") == 0) && (dup_coord(tet, TD_PIECE));
	(ft_strcmp(name, "TL_PIECE") == 0) && (dup_coord(tet, TL_PIECE));
	(ft_strcmp(name, "S_PIECE") == 0) && (dup_coord(tet, S_PIECE));
	(ft_strcmp(name, "SR_PIECE") == 0) && (dup_coord(tet, SR_PIECE));
	(ft_strcmp(name, "Z_PIECE") == 0) && (dup_coord(tet, Z_PIECE));
	(ft_strcmp(name, "ZR_PIECE") == 0) && (dup_coord(tet, ZR_PIECE));
	return (tet);
}

int		dup_coord(int *dst, int *src)
{
	int	pdst;
	int	i;

	i = 0;
	pdst = dst;
	while (i < 8)
	{
		pdst[i] = src[i];
		i++;
	}
	return (1);
}
