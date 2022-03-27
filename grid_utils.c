/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 05:21:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/26 05:21:12 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	insert_piece(char **grid, int *tet, char c)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = 0;
	while (i < 8)
	{
		y = tet[i + 1];
		x = tet[i];
		grid[y][x] = c;
		i += 2;
	}
}

void	clear_piece(char **grid, int *tet)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = 0;
	while (i < 8)
	{
		y = tet[i + 1];
		x = tet[i];
		grid[y][x] = '.';
		i += 2;
	}
}

void	print_grid(char **grid, int size)
{
	int	i;

	i = -1;
	while (grid[++i])
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
	}
	free_grid(grid, size);
}
