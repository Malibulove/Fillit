/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/01 14:10:59 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include <stdio.h>

int	check_grid(char **grid)
{
	int	x;
	int	y;
	int	status;

	status = 1;
	x = 0;
	while (x < 4)
	{
//		printf("\n");
		y = 0;
		while (y < 4)
		{
			if (grid[x][y] != '.' && grid[x][y] != '#')
					status = -1;
//			printf("grid[%d][%d] = %c\n", x, y, grid[x][y]);
			y++;
		}
	x++;
	}
	y = 0;
	return (status);
}
