/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 05:14:21 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/26 05:14:25 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int	count_tet(t_tetris *stack)
{
	int			c;
	t_tetris	*tmp;

	tmp = stack;
	c = 0;
	while (tmp)
	{
		c++;
		tmp = tmp->next;
	}
	return (c);
}

int	start_size(t_tetris *stack)
{
	int		blocks;
	int		size;

	size = 2;
	blocks = (count_tet(stack) * 4);
	while (blocks > (size * size))
		size += 1;
	return (size);
}

char	*gen_line(int col)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *)malloc(sizeof(char) * col + 1);
	if (!line)
		return (NULL);
	while (i < col)
	{
		line[i] = '.';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**gen_grid(int size)
{
	char	**grid;
	int		i;
	char	*line;

	i = 0;
	grid = (char **)malloc(sizeof(char *) * size + 1);
	if (!grid)
		return (NULL);
	while (i < size)
	{
		grid[i] = (char *)malloc(sizeof(char) * size + 1);
		line = gen_line(size);
		ft_strcpy(grid[i], line);
		free(line);
		i++;
	}
	grid[i] = NULL;
	return (grid);
}
