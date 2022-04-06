/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/30 14:34:42 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	one_grid(const int fd, char *line)
{
	int	n_line;
	int	count;

	n_line = 0;
	count = 0;
	while (n_line < 4)
	{
		if (get_next_line(fd, &line))
		{
			count += h_count(line);
			if (ft_strlen(line) != 4 || count > 4 || !check_char(line))
				return(error_line(line));
			free(line);
		}
		n_line++;
	}
	if (count < 4)
		return(error_handling());
	return (1);
}

int	h_count(char *line)
{
	int	count;

	count = 0;
	if (!line)
		return (0);
	while (*line)
	{
		if (*line == '#')
			count++;
		line++;
	}
	return (count);
}

int	check_char(char *line)
{
	while (*line)
	{
		if (*line != '.' && *line != '#')
			return (0);
		line++;
	}
	return (1);
}

t_tetris	*id_to_coord(t_tetris *stack)
{
	t_tetris	*head;
	t_tetris	*piece;
	char		*tet_id;
	char		c;

	c = 'A';
	head = NULL;
	while (stack)
	{
		tet_id = stack->tet_id;
		if (!tet_id)
			return (NULL);
		if (head == NULL)
		{
			head = add_piece(char_to_int_id(tet_id), c++);
			if (!head)
				return (NULL);
		}
		else
		{
			piece = append(char_to_int_id(tet_id), head, c++);
			if (!piece)
				return (NULL);
		}
		stack = stack->next;
	}
	return (head);
}

int	dup_coord(int *dst, int *src)
{
	int	*pdst;
	int	i;

	i = 0;
	pdst = dst;
	while (i < 8)
	{
		pdst[i] = src[i];
		i++;
	}
	return (1);
}
