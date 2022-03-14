/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:54:19 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/14 18:02:18 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	print_status(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int			check_plc(char **map, int x, int y, t_trm tetrimino)
{
	int mapsize;
	int i;

	i = 0;
	mapsize = 0;
	while (map[i][mapsize])
		mapsize++;
	while (i < 3)
	{
		if (x + tetrimino.rows[i] < 0 || y + tetrimino.cols[i] < 0)
			return (0);
		if (x + tetrimino.rows[i] > mapsize - 1 ||
				y + tetrimino.cols[i] > mapsize - 1)
			return (0);
		if (map[x + tetrimino.rows[i]][y + tetrimino.cols[i]] != '.')
			return (0);
		i++;
	}
	return (1);
}

void		place_tetrimino(char **map, int x, int y, t_trm tetrimino)
{
	int i;

	i = 0;
	map[x][y] = tetrimino.alphabet;
	while (i < 3)
	{
		map[x + tetrimino.rows[i]][y + tetrimino.cols[i]] = tetrimino.alphabet;
		i++;
	}
	print_status(map);
}

void		remove_tetrimino(char **map, int x, int y, t_trm tetrimino)
{
	int i;

	i = 0;
	map[x][y] = '.';
	while (i < 3)
	{
		map[x + tetrimino.rows[i]][y + tetrimino.cols[i]] = '.';
		i++;
	}
}

int			back_tracking(t_trm *arr_tetriminos, char **map, int mapsize)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(arr_tetriminos->alphabet))
		return (1);
	while (x < mapsize)
	{
		while (y < mapsize)
		{
			if (map[x][y] == '.' && check_plc(map, x, y, *arr_tetriminos) == 1)
			{
				place_tetrimino(map, x, y, *arr_tetriminos);
				if (back_tracking(arr_tetriminos + 1, map, mapsize))
					return (1);
				else
					remove_tetrimino(map, x, y, *arr_tetriminos);
			}
			y++;
		}
		x++;
		y = 0;
	}
	return (0);
}

char		**solver(t_trm *arr_tetriminos)
{
	int		solver_result;
	int		mapsize;
	char	**map;
	int		i;

	map = NULL;
	i = 0;
	mapsize = 2;
	solver_result = 0;
	map = make_bigger_map(mapsize, map);
	while (solver_result == 0)
	{
		solver_result = back_tracking(arr_tetriminos, map, mapsize);
		if (solver_result == 0)
		{
			mapsize++;
			while (map[i])
				free(map[i++]);
			free(map);
			map = make_bigger_map(mapsize, map);
		}
		i = 0;
	}
	return (map);
}
