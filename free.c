/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:25:06 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/30 14:09:02 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
