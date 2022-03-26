/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:30:25 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/26 02:30:26 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int	*trans_coord(int *tet)
{
	int	lx;
	int	ly;
	int	i;
	int	size;

	size = 4;
	lx = smallest_x(tet);
	ly = smallest_y(tet);
	i = 0;
	while (size--)
	{
		tet[i] -= lx;
		tet[i + 1] -= ly;
		i += 2;
	}
	return (tet);
}

int	smallest_x(int *tet)
{
	int	x;
	int	i;
	int	size;

	size = 4;
	i = 0;
	x = tet[i];
	while (size--)
	{
		if (tet[i] >= 0 && tet[i] <= 3)
			if (tet[i] < x)
				x = tet[i];
		i += 2;
	}
	return (x);
}

int	smallest_y(int *tet)
{
	int	y;
	int	i;
	int	size;

	size = 4;
	i = 1;
	y = tet[i];
	while (size--)
	{
		if (tet[i] >= 0 && tet[i] <= 3)
			if (tet[i] < y)
				y = tet[i];
		i += 2;
	}
	return (y);
}
