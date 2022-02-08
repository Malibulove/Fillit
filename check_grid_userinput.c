/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/02 18:21:31 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int	check_grid(char **grid, int grid_count)
{
	int	x;
	int	z;
	int	y;
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
		if (ft_strcmp(&grid[x][y], "\0"))
			return (-1);
		x++;
		}
	z++;
	y = 0;
	if (count_hash != 4)
		return (-1);
	for (int i = 0; i < 8; i++)	//testing ...sorry, this damn thing "continues too long" and stacks the rest of the coordinates but the function itself works
	printf("%d", tet[i]);		//testing
	return (*tet);
}
