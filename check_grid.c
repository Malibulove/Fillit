/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/01 12:40:30 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include <stdio.h>

int	check_grid(char **grid)
{
	int	x;
	int	y;
	x = 0;
	while (x < 4)
	{
		printf("\n");
		y = 0;
		while (y < 4)
		{
			printf("grid[%d][%d] = %c\n", x, y, grid[x][y]);
			if (grid[x][y] != '.' && grid[x][y] != '#')
				printf("error\n");
			y++;
		}
//	if (grid[x][y] != '\n')
//		return (-1);
	x++;
	}
	y = 0;
//	if (grid[x][y] != '\n')
//		return (-1);
	printf("je suis a la fin de check grid");
	return (1);
}
