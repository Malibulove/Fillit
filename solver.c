/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:54:19 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/15 12:20:56 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit/h"

int		stack_tet(t_tetris *stack)
{
	int *stacked_tet;
	int x;
	int y;

	stacked_tet = (int *)malloc(sizeof(int) * 8);
	if (!stack)
	{
		free(stacked_tet);
		return (-1);
	}
	dup_coord(stacked_tet, stack->tet_id);
	return (stacked_tet);
}

int		solve_tet(int *tet2, int *tet, int size)
{
	int x;
	int y;

	y = -1;
	tet = stacked_tet(tet);     // i don't really know if storing can work like this
	tet2 = stacked_tet(tet2);
	while (y < size)
	{
		x = -1;
		while (x < size)
		{
			shift_tet(tet, x, y);
			if (collision(tet2, tet, size) != 1)    // we only move tet and tet2 stays, that's probably a problem later
				return (1);
            x++;
		}
        y++;
	}
	free(tet);
	return (0);
}

int		*x_shift(int *tab, int x)
{
	int i;
	int size;

	size = 4;
	i = 0;
	while (size--)
	{
		tab[i] = tab[i] + x;
		i += 2;
	}
	return (tab);
}

int		*y_shift(int *tab, int y)
{
	int i;
	int size;

	size = 4;
	i = 1;
	while (size--)
	{
		tab[i] = tab[i] + y;
		i += 2;
	}
	return (tab);
}

int		*shift_tet(int *tab, int x, int y)
{
	tab = x_shift(tab, x);
	tab = y_shift(tab, y);
	return (tab);
}
