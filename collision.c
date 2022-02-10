/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:09:30 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/10 15:44:50 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	top_x(int *tet)
{
	int	line_count;
	int	i;
	int	x;

	i = 0;
	line_count = 0;
	x = tet[i];

	while (line_count < 3)
	{
		i = i + 2;
		if (x < tet[i])
			x = tet[i];
		line_count++;
	}
	return(x);
}
int	top_y(int *tet)
{
	int	column_count;
	int	i;
	int	y;

	i = 1;
	column_count = 0;
	y = tet[i];

	while (column_count < 3)
	{
		i = i + 2;
		if (y < tet[i])
			y = tet[i];
		column_count++;
	}
	return(y);
}

int	box_collision(int *tet, int size)
{
	int	x;
	int	y;

	x = top_x(tet);
	y = yop_y(tet);
	if (x >= size || y >= size)
		return(1);
	return(0);
}

int	piece_collision(char **grid, int *tet)
{
	
}

int	collision(char **grid, int *tet, int size)
{
	if (box_collision(tet, size) != 0 && piece_collision(tet, size) != 0)
		return(1);
	else
		return(0);
}
