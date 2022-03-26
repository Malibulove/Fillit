/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:30:43 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/26 02:30:44 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

t_tetris	*add_piece(void *tet_id, char tet_c)
{
	t_tetris	*piece;

	piece = (t_tetris *)malloc(sizeof(t_tetris));
	piece->tet_id = tet_id;
	piece->c = tet_c;
	piece->next = NULL;
	return (piece);
}

t_tetris	*append(void *tet_id, t_tetris *head, char c)
{
	t_tetris	*cursor;
	t_tetris	*piece;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	piece = add_piece(tet_id, c);
	cursor->next = piece;
	return (head);
}

t_tetris	*store_tet(const int fd, char *line)
{
	int			*tet;
	char		*tet_id;
	t_tetris	*first;
	t_tetris	*piece;
	char		c;

	c = 'A';
	first = NULL;
	while (1)
	{
		tet = trans_coord(one_tetris(fd, line));
		tet_id = check_tet(tet);
		if (!tet_id)
			ft_exit();
		if (first == NULL)
			first = add_piece(tet_id, c++);
		else
			piece = append(tet_id, first, c++);
		free(tet);
		if (!(get_next_line(fd, &line)))
			break ;
		free(line);
	}
	close(fd);
	return (first);
}

int	*one_tetris(const int fd, char *line)
{
	int		x;
	int		y;
	int		*tet;
	int		i;

	y = -1;
	tet = (int *)malloc(sizeof(int) * 8);
	i = 0;
	while (++y <= 3)
	{
		x = 0;
		get_next_line(fd, &line);
		while (line[x])
		{
			if (line[x] == '#')
			{
				tet[i] = x;
				tet[i + 1] = y;
				i += 2;
			}
			x++;
		}
		free(line);
	}
	return (tet);
}
