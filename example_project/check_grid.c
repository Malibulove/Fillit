/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/14 18:00:39 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

char	**make_bigger_map(int mapsize, char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(map = (char**)malloc(sizeof(char*) * mapsize + 1)))
		return (NULL);
	while (x < mapsize)
	{
		if (!(map[x] = (char*)malloc(sizeof(char) * mapsize + 1)))
			return (NULL);
		while (y < mapsize)
		{
			map[x][y] = '.';
			y++;
		}
		map[x][y] = '\0';
		y = 0;
		x++;
	}
	map[x] = 0;
	return (map);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	starting_point(char *block)
{
	int i;

	i = 0;
	while (block[i] != '#')
		i++;
	return (i);
}

static int	check_rows(char *block, t_trm *tetriminos)
{
	int	rows;
	int	i;
	int	hash;
	int	r;

	rows = 0;
	hash = 1;
	i = starting_point(block) + 1;
	r = 0;
	while (hash++ < 4)
	{
		if (block[i] == '.')
			rows++;
		while (block[i] == '.')
			i++;
		i++;
		tetriminos->rows[r++] = rows;
	}
	return (0);
}

static int	check_cols(char *block, t_trm *tetriminos)
{
	int	i;
	int	hash;
	int	count;
	int	c;

	hash = 1;
	i = starting_point(block) + 1;
	count = 4;
	c = 0;
	while (hash++ < 4)
	{
		if (block[i] == '.')
		{
			while (block[i] == '.')
			{
				i++;
				count--;
			}
			count = 4 + count;
		}
		count--;
		i++;
		tetriminos->cols[c++] = (4 - count);
	}
	return (0);
}

int			struct_creator(t_trm *tetriminos, char **blocks)
{
	int		i;
	char	c;

	i = 0;
	c = 'A';
	while (blocks[i])
	{
		check_rows(blocks[i], &tetriminos[i]);
		check_cols(blocks[i], &tetriminos[i]);
		tetriminos[i].alphabet = c;
		c = c + 1;
		free(blocks[i]);
		i++;
	}
	return (0);
}
