/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:54:19 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/16 15:37:57 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

//int		stack_tet(t_tetris *stack)
//{
//	int *stacked_tet;

//	stacked_tet = (int *)malloc(sizeof(int) * 8);
//	if (!stack)
//	{
//		free(stacked_tet);
//		return (-1);
//	}
//	dup_coord(stacked_tet, stack->tet_id);
//	return (*stacked_tet);
//}

int		solve_tet(int *tet2, int *tet, int size)
{
	int x;
	int y;

	y = -1;
//	*tet = stack_tet(tet);
//	*tet2 = stack_tet(tet2);
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

int		*shift_tet(int *tet, int x, int y)
{
	tet = x_shift(tet, x);
	tet = y_shift(tet, y);
	return (tet);
}
