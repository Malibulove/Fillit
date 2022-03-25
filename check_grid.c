/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:09 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/24 11:37:32 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int		read_one(const int fd, char *line)
{
	int n_line;
	int count;

	n_line = 0;
	count = 0;
	while (n_line < 4)
	{
		if (get_next_line(fd, &line))
		{
			count += h_count(line);
			if (ft_strlen(line) != 4 || count > 4 || !chk_char(line))
			{
				printf("grid problem read one\n");
				ft_exit();
			}
			free(line);
		}
		n_line++;
	}
	if (count < 4)
		ft_exit();
	return (1);
}

int		h_count(char *line)
{
	int count;

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

int		chk_char(char *line)
{
	while (*line)
	{
		if (*line != '.' && *line != '#')
			return (0);
		line++;
	}
	return (1);
}

int	error_check(char **grid, int count_hash, int i, int x, int y)
{
	if (&grid[x][y] == NULL && i == 4)
	{
		if (count_hash != 4)
			return (-1);
	}
	else if (count_hash != 4 || ft_strcmp(&grid[x][y], "\0"))
		return (-1);
	return (1);
}

int	*print_tet(int *tet, int grid_count)
{
	int	j;
	int	test;

	j = 0;
	while (j < 8)
	{
		if (j == 0 || j == 2 || j == 4 || j == 6)
		{
			test = (tet[j] - (5 * grid_count));
			printf("%d", test);
		}
		else
			printf("%d", tet[j]);
		j++;
	}
	printf(" grid count = %d", grid_count);
	printf("\n");
	return (tet);
}

// -------------- TRANSLATING THE COORDINATES --------------------------------------------------------
int		*trans_coord(int *tet)
{
	int lx;
	int ly;
	int i;
	int size;

	size = 4;
	lx = low_x(tet);
	ly = low_y(tet);
	i = 0;
	while (size--)
	{
		tet[i] -= lx;
		tet[i + 1] -= ly;
		i += 2;
	}
	return (tet);
}

int		low_x(int *tet)
{
	int x;
	int i;
	int size;

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

int		low_y(int *tet)
{
	int y;
	int i;
	int size;

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

// -------------- LISTING --------------------------------------------------------

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
		if (!(tet_id = get_tetid(tet)))
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



char	*get_tetid(int *tet) // finds the name of the tetrimino by comparing it to the arrays in fillit.h
{
	char	*name;

	t_piece i_piece(void);
	t_piece ih_piece(void);
	t_piece o_piece(void);
	t_piece l_piece(void);
	t_piece lr_piece(void);
	t_piece ld_piece(void);
	t_piece ll_piece(void);
	t_piece j_piece(void);
	t_piece jr_piece(void);
	t_piece jd_piece(void);
	t_piece jl_piece(void);
	t_piece tt_piece(void);
	t_piece tr_piece(void);
	t_piece td_piece(void);
	t_piece tl_piece(void);
	t_piece ss_piece(void);
	t_piece sr_piece(void);
	t_piece z_piece(void);
	t_piece zr_piece(void);
	name = check_tet(tet);
	printf("It's a match with : %s\n", name);
	return (name);
}

char	*check_tet(int *tet)
{
	char *name;
	name = NULL;
	((tetcmp(tet, i_piece().coord) == 1) && (name = "i_piece"));
	((tetcmp(tet, ih_piece().coord) == 1) && (name = "ih_piece"));
	((tetcmp(tet, o_piece().coord) == 1) && (name = "o_piece"));
	((tetcmp(tet, l_piece().coord) == 1) && (name = "l_piece"));
	((tetcmp(tet, lr_piece().coord) == 1) && (name = "lr_piece"));
	((tetcmp(tet, ld_piece().coord) == 1) && (name = "ld_piece"));
	((tetcmp(tet, ll_piece().coord) == 1) && (name = "ll_piece"));
	((tetcmp(tet, j_piece().coord) == 1) && (name = "j_piece"));
	((tetcmp(tet, jr_piece().coord) == 1) && (name = "jr_piece"));
	((tetcmp(tet, jd_piece().coord) == 1) && (name = "jd_piece"));
	((tetcmp(tet, jl_piece().coord) == 1) && (name = "jl_piece"));
	((tetcmp(tet, tt_piece().coord) == 1) && (name = "tt_piece"));
	((tetcmp(tet, tr_piece().coord) == 1) && (name = "tr_piece"));
	((tetcmp(tet, td_piece().coord) == 1) && (name = "td_piece"));
	((tetcmp(tet, tl_piece().coord) == 1) && (name = "tl_piece"));
	((tetcmp(tet, ss_piece().coord) == 1) && (name = "ss_piece"));
	((tetcmp(tet, sr_piece().coord) == 1) && (name = "sr_piece"));
	((tetcmp(tet, z_piece().coord) == 1) && (name = "z_piece"));
	((tetcmp(tet, zr_piece().coord) == 1) && (name = "zr_piece"));
	return(name);
}

int	tetcmp(int *tet, int *libtet)
{
	int	i;

	i = 0;
	printf("tet inside tet cmp\n");
	while (i < 8)
	{
		printf( "coord[%d] => %d | %d\n", i, tet[i], libtet[i]);
		if (tet[i] != libtet[i])
			return (-1);
		i++;
	}
	return (1);
}

int		*convert_id(char *name)
{
	int	*tet;
	tet = (int *)malloc(sizeof(int) * 8);
	printf("Shape of tetriminos ==> %s ", name);
	(ft_strcmp(name, "i_piece") == 0) && (dup_coord(tet, i_piece().coord));
	(ft_strcmp(name, "ih_piece") == 0) && (dup_coord(tet, ih_piece().coord));
	(ft_strcmp(name, "o_piece") == 0) && (dup_coord(tet, o_piece().coord));
	(ft_strcmp(name, "l_piece") == 0) && (dup_coord(tet, l_piece().coord));
	(ft_strcmp(name, "lr_piece") == 0) && (dup_coord(tet, lr_piece().coord));
	(ft_strcmp(name, "ld_piece") == 0) && (dup_coord(tet, ld_piece().coord));
	(ft_strcmp(name, "ll_piece") == 0) && (dup_coord(tet, ll_piece().coord));
	(ft_strcmp(name, "j_piece") == 0) && (dup_coord(tet, j_piece().coord));
	(ft_strcmp(name, "jr_piece") == 0) && (dup_coord(tet, jr_piece().coord));
	(ft_strcmp(name, "jd_piece") == 0) && (dup_coord(tet, jd_piece().coord));
	(ft_strcmp(name, "jl_piece") == 0) && (dup_coord(tet, jl_piece().coord));
	(ft_strcmp(name, "tt_piece") == 0) && (dup_coord(tet, tt_piece().coord));
	(ft_strcmp(name, "tr_piece") == 0) && (dup_coord(tet, tr_piece().coord));
	(ft_strcmp(name, "td_piece") == 0) && (dup_coord(tet, td_piece().coord));
	(ft_strcmp(name, "tl_piece") == 0) && (dup_coord(tet, tl_piece().coord));
	(ft_strcmp(name, "ss_piece") == 0) && (dup_coord(tet, ss_piece().coord));
	(ft_strcmp(name, "sr_piece") == 0) && (dup_coord(tet, sr_piece().coord));
	(ft_strcmp(name, "z_piece") == 0) && (dup_coord(tet, z_piece().coord));
	(ft_strcmp(name, "zr_piece") == 0) && (dup_coord(tet, zr_piece().coord));
	int i;
	i = 0;
	printf("= ");
	while (i < 8)
	{
		printf("%d", tet[i]);
		i++;
	}
	printf("\n");
	i = 0;
	return (tet);
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
		if (head == NULL)
			head = add_piece(convert_id(tet_id), c++);
		else
			piece = append(convert_id(tet_id), head, c++);
		stack = stack->next;
	}
	printf("end of id to coord\n");
	return (head);
}

int		dup_coord(int *dst, int *src)
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

void	ft_exit(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

int		*one_tetris(const int fd, char *line)
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
