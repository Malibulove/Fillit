/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/02 09:56:07 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int	check_grid(char **grid, int grid_count)
{
	int	x;
	int	y;
	int	count_hash;

	count_hash = 0;
	x = 0 + (grid_count * 5);
	while (x < (4 + (grid_count * 5)))
	{
		y = 0;
		printf("\n");
		while (y < 4)
		{
//			printf("grid[%d][%d] = %c\n", x, y, grid[x][y]);
			if (grid[x][y] != '.' && grid[x][y] != '#')
				return (-1);
			if (grid[x][y] == '#')
				count_hash++;
			y++;
		}
		if (ft_strcmp(&grid[x][y], "\0"))
			return (-1);
		x++;
	}
	y = 0;
	if (count_hash != 4)
		return (-1);
	return (1);
}
