/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/01/28 17:06:42 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include <stdio.h>

int	check_grid(char **grid)
{
	int	x;
	int	y;
	x = 0;
	printf("je suis dans check grid\n");
	while (x < 4)
	{
		printf("je suis dans le premier while\n");
		y = 0;
		printf("grid[%d][%d] = %c\n", x, y, grid[x][y]);
		while (y < 4)
		{
			printf("je suis dans le deuxieme while\n");
//			if (grid[x][y] != '#' || grid [x][y] != '.')
//				return (-1);
			y++;
			printf("grid[%d][%d]·=·%c\n", x, y, grid[x][y]);
		}
//	if (grid[x][y] != '\n')
//		return (-1);
	x++;
	}
	y = 0;
	if (grid[x][y] != '\n')
		return (-1);
	printf("je suis a la fin de check grid");
	return (1);
}
