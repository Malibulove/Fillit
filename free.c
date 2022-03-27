/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:25:06 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/26 02:25:18 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	stack_free(t_tetris *stack)
{
	t_tetris	*tmp;

	tmp = NULL;
	while (stack)
	{
		tmp = stack;
		stack = tmp->next;
		free(tmp);
	}
}

void	stack_free_coord(t_tetris *stack)
{
	t_tetris	*tmp;

	tmp = NULL;
	while (stack)
	{
		tmp = stack;
		stack = tmp->next;
		free(tmp->tet_id);
		free(tmp);
	}
}

void	free_grid(char **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&grid[i]);
		i++;
	}
	free(grid);
}
