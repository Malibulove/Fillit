/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/02 16:29:00 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

static int	 **hash_coordinate(char **grid, int x, int y, int z, int count_hash)
{
	int		**hash_xy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	hash_xy = (int **)malloc(sizeof(int *) * 500);
//	printf("count hash n°%d = %c with coord = [%d][%d]\n",count_hash,
// grid[z][y], z, y);
	printf("count hash = %d\n", count_hash);
	printf("x = %d\n", x);
	printf("z = %d\n", z);
	printf("y = %d\n", y);
	printf("grid[x][y] = %c\n", grid[x][y]);
/* 	if (count_hash < 4)
	{
		hash_xy[i][0] = z;
		hash_xy[i][1] = y;
	}
	if (count_hash == 4)
	{
		hash_xy[i][2] = z;
		hash_xy[i][3] = y;
	}
*/
	return (hash_xy);
}

int	check_grid(char **grid, int grid_count)
{
	int	x;
	int	z;
	int	y;
	int	count_hash;

	count_hash = 0;
	z = 0;
	x = 0 + (grid_count * 5);
	while (x < (4 + (grid_count * 5)))
	{
		y = 0;
//		printf("\n");
		while (y < 4)
		{
//			printf("grid[%d][%d] = %c\n", x, y, grid[x][y]);
			if (grid[x][y] != '.' && grid[x][y] != '#')
				return (-1);
			if (grid[x][y] == '#')
			{
				count_hash++;
				hash_coordinate(grid, x, y, z, count_hash);
			}
			y++;
		}
		if (ft_strcmp(&grid[x][y], "\0"))
			return (-1);
		x++;
		z++;
	}
	y = 0;
	if (count_hash != 4)
		return (-1);
	return (1);
}
