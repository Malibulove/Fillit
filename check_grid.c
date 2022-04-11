/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/07 13:27:15 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_char(char *line)
{
	while (*line)
	{
		if (*line != '.' && *line != '#')
			return (0);
		line++;
	}
	return (1);
}

static int	h_count(char *line)
{
	int	count;

	count = 0;
	if (!line)
		return (0);
	while (*line)
	{
		if (*line == '#')
			count++;
		if (*line == '\0')
			return (0);
		line++;
	}
	return (count);
}

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
			{
				free(line);
				return (0);
			}
			free(line);
		}
		n_line++;
	}
	if (count < 4)
		return (0);
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
			head = add_piece(char_to_int_id(tet_id), c++);
		else
			piece = append(char_to_int_id(tet_id), head, c++);
		if (!piece || !head)
			return (NULL);
		stack = stack->next;
	}
	return (head);
}

int	*convert_char_to_int(const int fd, char *line, int *tet)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = -1;
	while (++y <= 3)
	{
		x = -1;
		get_next_line(fd, &line);
		while (line[++x])
		{
			if (line[x] == '#')
			{
				tet[i] = x;
				tet[i + 1] = y;
				i += 2;
			}
		}
		free(line);
	}
	return (tet);
}
