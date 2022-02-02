/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/02 07:45:17 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int	check_grid(char **grid)
{
	int	x;
	int	y;
	int	count_hash;

	count_hash = 0;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
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
	if (ft_strcmp(&grid[x][y], "\0") || count_hash != 4)
		return (-1);
	return (1);
}
