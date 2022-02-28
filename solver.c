/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:54:19 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/28 13:32:46 by ekantane         ###   ########.fr       */
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

int		solve_tet(char **grid, int *tet, int size)
{
	int x;
	int y;


//	*tet = stack_tet(tet);
//	*tet2 = stack_tet(tet2);

if (collision(grid, tet, size) == 1)
{
	x = 0;
	while (x < size)
	{
		y = 0;
		x++;
		shift_tet(tet, x, y);
		if (collision(grid, tet, size) != 1)
			return (0);
		if (collision(grid, tet, size) == 1)
			{
			x = x - 1;
			while (y < size)
			{
			y++;
			shift_tet(tet, x, y);
				if (collision(grid, tet, size) != 1)
					return (1);
				if (collision(grid, tet, size) == 1)
					x++;
			}
			}
	}
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
