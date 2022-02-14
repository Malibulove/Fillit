/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:09:30 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/10 15:44:50 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int	top_x(int *tet)
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
	return(x);
}
int	top_y(int *tet)
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
	return(y);
}

int	box_collision(int *tet, int size)
{
	int	x;
	int	y;

	x = top_x(tet);
	y = top_y(tet);
	if (x >= size || y >= size)
		return(1);
	return(0);
}

int	piece_collision(int *tet2, int *tet)
{
	int size;
	int i;
	int j;
	int x;
	int y;
	char **grid;

	i = 0;
	j = 1;
	x = 0;
	y = 0;
	size = 4;
	grid = NULL;
	**grid = grid[x][y];
	while (x < 4)
	{
		grid[x][y] = tet2[i];
		i = i + 1;
			while (y < 4)
			{
				grid[x][y] = tet2[j];
				j = j + 1;
				y++;
				j++;
			}
		x++;
		i++;
	}
	i = 0;
	while (size > 0)
	{
		if (grid[tet[i + 1]][tet[i]] != '.')
			return (1);
		i = i + 2;
		size--;
	}
	return (0);
}

int	collision(int *tet2, int *tet, int size)
{
	if (box_collision(tet, size) != 0 && piece_collision(tet2, tet) != 0)
		return(1);
	else
		return(0);
}
