/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:09:30 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/17 10:54:14 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

/* This and the following function measure the maximum x and y coordinates of 
the tetriminos when the piece is positioned in the origo. */
int	biggest_x(int *tet)
{
	int	line_count;
	int	i;
	int	x;

	i = 0;
	line_count = 0;
	x = tet[i];
	while (line_count < 3)
	{
		i = i + 2;
		if (x < tet[i])
			x = tet[i];
		line_count++;
	}
	return (x);
}

int	biggest_y(int *tet)
{
	int	column_count;
	int	i;
	int	y;

	i = 1;
	column_count = 0;
	y = tet[i];
	while (column_count < 3)
	{
		i = i + 2;
		if (y < tet[i])
			y = tet[i];
		column_count++;
	}
	return (y);
}

/* If the maximum x and y coordinates of the tetriminos are bigger or the
same (is this right?) as the size, the function returns a flag meaning
the collision happens. */
int	box_collision(int *tet, int size)
{
	int	x;
	int	y;

	x = biggest_x(tet);
	y = biggest_y(tet);
	if (x >= size || y >= size)
		return (1);
	return (0);
}

/* Here we check if the coordinates of tetriminos inside the grid array 
correspond to the first tetrimino as hashes.
If yes (instead of periods), theres collision. */
int	piece_collision(char **grid, int *tet)
{
	int	i;
	int	size;

	size = 4;
	i = 0;
	while (size--)
	{
		if (grid[tet[i + 1]][tet[i]] != '.')
			return (1);
		i = i + 2;
	}
	return (0);
}

/* This function serves a port for both the box collision and
the piece collision. */
int	collision(char **grid, int *tet, int size)
{
	return (!(box_collision(tet, size)) && !(piece_collision(grid, tet)));
}
