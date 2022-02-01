/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:38:59 by ycucchi           #+#    #+#             */
/*   Updated: 2022/01/28 15:43:29 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

we need to handle errors like
- size of grid (4 x 4)
- character (# or .)
- same tetriminos (there is 19 differents possibilities)
- more than 1 parameter (argc > 2)
- Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right)
- if multiples solutions exists,  the solution with the pieces placed in the order they are provided at their top-most left-most positions is correct. 

- size of grid (4 x 4) / character (# or .) and /n
int	check_grid(char **grid)
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		printf("je rentre dans la first loop");
		y = 0;
		while (y < 4)
		{
			printf("je rentre dans la seconde loop");
			if (grid[x][y] != '#' || grid [x][y] != '.')
				return (-1);
			y++;
		}
	if (grid[x][y] != '\n)
		return (-1);
	x++;
	}
	y = 0;
	if (grid[x][y] != '\n')
		return (-1);
	return (1);




int	i;
char	grid[line][column]
while (grid[i][column]
while (grid[line][i] != '\n')
	i++;
if (i != 3)
