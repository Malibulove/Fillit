/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 05:21:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/30 14:47:05 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (!tet)
		return;
	while (i < 8)
	{
		y = tet[i + 1];
		x = tet[i];
		grid[y][x] = '.';
		i += 2;
	}
}

void	print_grid(char **grid)
{
	int	i;

	i = -1;
	while (grid[++i])
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
	}
}
