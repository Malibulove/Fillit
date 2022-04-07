/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:30:43 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/07 16:32:30 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	*convert_char_to_int(const int fd, char *line, int *tet)
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

t_tetris	*add_piece(void *tet_id, char tet_c)
{
	t_tetris	*piece;

	piece = (t_tetris *)malloc(sizeof(t_tetris));
	if (!piece || !tet_id)
	{
		stack_free(piece);
		return (NULL);
	}
	piece->tet_id = tet_id;
	piece->c = tet_c;
	piece->next = NULL;
	return (piece);
}

t_tetris	*append(void *tet_id, t_tetris *head, char c)
{
	t_tetris	*cursor;
	t_tetris	*piece;

	if (!tet_id)
		return (NULL);
	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	piece = add_piece(tet_id, c);
	cursor->next = piece;
	return (head);
}

static t_tetris	*store_helper(t_tetris *first, char *tet_id)
{
	t_tetris	*piece;
	char		c;

	piece = NULL;
	c = 'A';
	if (first == NULL)
		first = add_piece(tet_id, c++);
	else
		piece = append(tet_id, first, c++);
	return (first);
}

static int	*one_tetris(const int fd, char *line)
{
	int		*tet;

	tet = (int *)malloc(sizeof(int) * 8);
	if (!tet)
	{
		free(tet);
		return (NULL);
	}
	return (convert_char_to_int(fd, line, tet));
}

t_tetris	*store_tet(const int fd, char *line)
{
	int			*tet;
	char		*tet_id;
	t_tetris	*first;

	first = NULL;
	while (1)
	{
		tet = trans_coord(one_tetris(fd, line));
		tet_id = check_tet(tet);
		if (!tet || !tet_id)
		{
			free(tet);
			free(tet_id);
			stack_free(first);
			return (NULL);
		}
		first = store_helper(first, tet_id);
		free(tet);
		if (!(get_next_line(fd, &line)))
			break ;
		free(line);
	}
	close(fd);
	return (first);
}
