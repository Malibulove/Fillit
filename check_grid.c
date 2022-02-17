/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/17 15:58:10 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

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
				if (count_hash >= 4)
					return(-1);
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
	if (error_check(grid, count_hash, i, x, y) != 1)
		return (-1);
	print_tet(tet, grid_count);
	if (!store_tet(tet, grid_count))
		return (-1);
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
//	int	first_grid[8] = {0, 0, 0, 1, 0, 2, 0, 3};
//	int	new_tet;

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
/*
	if (piece_collision(first_grid, tet) == 1)
			{
			printf("the pieces collide\n");
			solve_tet(first_grid, tet, 10);
			printf("the pieces have been moved, this is the situation now: \n");
			j = 0;
			while (j < 8)
				{
					if (j == 0 || j == 2 || j == 4 || j == 6)
					{
						new_tet = (first_grid[j] - (5 * grid_count));
						printf("%d", new_tet);
					}
					else
						printf("%d", new_tet);
					j++;
				}
			}
	if (piece_collision(first_grid, tet) == 0)
			printf("the pieces do not collide\n");
*/
	return (tet);
}

// -------------- TRANSLATING THE COORDINATES --------------------------------------------------------

int	*trans_coord(int *tet, int grid_count)
{
	int	lx;
	int	ly;
	int	i;
	int	size;

	printf("enter trans cord\n");
	size = 4;
	lx = low_x(tet, grid_count);
	ly = low_y(tet);
	printf("lx = %d\n", lx);
	printf("ly = %d\n", ly);
	i = 0;
	while (size--)
	{
		tet[i] = (tet[i] - grid_count * 5) - lx;
		tet[i + 1] = tet[i + 1] - ly;
		i = i + 2;
	}
	printf("sortie\n");
	return (tet);
}

int		low_x(int *tet, int grid_count)
{
	int x;
	int i;
	int size;

	size = 4;
	i = 0;
	printf("tet i = %d\n", tet[i]);
	x = tet[i] - (grid_count * 5);
	printf("x avant loop = %d\n", x);
	while (size--)
	{
		x = tet[i] - (grid_count * 5);
		if ((tet[i] - (grid_count * 5)) >= 0 && (tet[i] - (grid_count * 5)) <= 3)
			if (tet[i] < x)
				x = tet[i] - (grid_count * 5);
		i += 2;
	}
	i = 0;
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
		i += 2;
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
	int			i;

	i = 0;
	c = 'A';
	first = NULL;
	if (grid_count == 0)
		tet_id = get_tetid(tet);
//	if (!tet_id)
//		exit(EXIT_FAILURE);
	while (grid_count != 0)
	{
		tet_translated = trans_coord(tet, grid_count);
		printf("tet translated = %d\n", tet_translated[0]);
		printf("tet translated = %d\n", tet_translated[1]);
		printf("tet translated = %d\n", tet_translated[2]);
		printf("tet translated = %d\n", tet_translated[3]);
		printf("tet translated = %d\n", tet_translated[4]);
		printf("tet translated = %d\n", tet_translated[5]);
		printf("tet translated = %d\n", tet_translated[6]);
		printf("tet translated = %d\n", tet_translated[7]);
		if (!(tet_id = get_tetid(tet)))
		{
			printf("GROS BUG\n");
			exit(EXIT_FAILURE);
		}
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
	if (tetcmp(tet, I_PIECE, sizeof(tet)) == 1)
		name = "I_PIECE";
	else if (tetcmp(tet, IH_PIECE, sizeof(tet)) == 1)
		name = "IH_PIECE";
	else if (tetcmp(tet, O_PIECE, sizeof(tet)) == 1)
		name = "O_PIECE";
	else if (tetcmp(tet, L_PIECE, sizeof(tet)) == 1)
		name = "L_PIECE";
	else if (tetcmp(tet, LR_PIECE, sizeof(tet)) == 1)
		name = "LR_PIECE";
	else if (tetcmp(tet, LD_PIECE, sizeof(tet)) == 1)
		name = "LD_PIECE";
	else if (tetcmp(tet, LL_PIECE, sizeof(tet)) == 1)
		name = "LL_PIECE";
	else if (tetcmp(tet, J_PIECE, sizeof(tet)) == 1)
		name = "J_PIECE";
	else if (tetcmp(tet, JR_PIECE, sizeof(tet)) == 1)
		name = "JR_PIECE";
	else if (tetcmp(tet, JD_PIECE, sizeof(tet)) == 1)
		name = "JD_PIECE";
	else if (tetcmp(tet, JL_PIECE,sizeof(tet)) == 1)
		name = "JL_PIECE";
	else if (tetcmp(tet, T_PIECE, sizeof(tet)) == 1)
		name = "T_PIECE";
	else if (tetcmp(tet, TR_PIECE, sizeof(tet)) == 1)
		name = "TR_PIECE";
	else if (tetcmp(tet, TD_PIECE, sizeof(tet)) == 1)
		name = "TD_PIECE";
	else if (tetcmp(tet, TL_PIECE, sizeof(tet)) == 1)
		name = "TL_PIECE";
	else if (tetcmp(tet, S_PIECE, sizeof(tet)) == 1)
		name = "S_PIECE";
	else if (tetcmp(tet, SR_PIECE, sizeof(tet)) == 1)
		name = "SR_PIECE";
	else if (tetcmp(tet, Z_PIECE, sizeof(tet)) == 1)
		name = "Z_PIECE";
	else if	(tetcmp(tet, ZR_PIECE, sizeof(tet)) == 1)
		name = "ZR_PIECE";
	printf("%s\n", name);
	return (name);
}

int	tetcmp(int *tet, int *libtet, int n) // (user input tet, pre-made tet, the size of the user input tet)
{
	int	i;

	i = 0;
	printf("n = %d\n", n);
	while (i < n)
	{
		printf("tet[%d] = %d\n", i, tet[i]);
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

t_tetris	*id_to_coord(t_tetris *stack)
{
	t_tetris	*head;
	t_tetris	*piece;
	char		*tet_id;
	char		c;

	c = 'A';
	head = NULL;
	while (stack)
	{
		tet_id = stack->tet_id;
		if (head == NULL)
			head = add_piece(convert_id(tet_id), c++);
		else
			piece = append(convert_id(tet_id), head, c++);
		stack = stack->next;
	}
	return (head);
}

int		dup_coord(int *dst, int *src)
{
	int	*pdst;
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
