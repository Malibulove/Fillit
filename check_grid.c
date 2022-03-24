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

int		check_grid(char **grid, int size)
{
	int	x;
	int	z;
	int	y;
	int	count_hash;
	int grid_count;

	grid_count = size;
	count_hash = 0;
	z = 0;
	x = 0 + (grid_count * 5);
	while (x < (4 + (grid_count * 5)))
	{
		y = 0;
		while (y < 4)
		{
			if (grid[x][y] != '.' && grid[x][y] != '#')
				return (-1);
			if (grid[x][y] == '#')
			{
				if (count_hash >= 4)
					return(-1);
				count_hash++;
			}
			y++;
		}
		if (ft_strcmp(&grid[x][y], "\0"))
			return (-1);
		x++;
		z++;
	}
	y = 0;
	if (error_check(grid, count_hash, size, x, y) != 1)
		return (-1);
	return(1);
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

void		give_value_to_tet(void)
{
	s_piece p1 = {"i_piece", {0,0,0,1,0,2,0,3}};
	s_piece p2 = {"ih_piece", {0,0,1,0,2,0,3,0}};
	s_piece p3 = {"o_piece", {0,0,1,0,0,1,1,1}};
	s_piece p4 = {"l_piece", {0,0,0,1,0,2,1,2}};
	s_piece p5 = {"lr_piece", {0,0,1,0,2,0,0,1}};
	s_piece p6 = {"ld_piece", {0,0,1,0,1,1,1,2}};
	s_piece p7 = {"ll_piece", {2,0,0,1,1,1,2,1}};
	s_piece p8 = {"j_piece", {1,0,1,1,0,2,1,2}};
	s_piece p9 = {"jr_piece", {0,0,0,1,1,1,2,1}};
	s_piece p10 = {"jd_piece", {0,0,1,0,0,1,0,2}};
	s_piece p11 = {"jl_piece", {0,0,1,0,2,0,2,1}};
	s_piece p12 = {"t_piece", {1,0,0,1,1,1,2,1}};
	s_piece p13 = {"tr_piece", {0,0,0,1,1,1,0,2}};
	s_piece p14 = {"td_piece", {0,0,1,0,2,0,1,1}};
	s_piece p15 = {"tl_piece", {1,0,0,1,1,1,1,2}};
	s_piece p16 = {"s_piece", {1,0,2,0,0,1,1,1}};
	s_piece p17 = {"sr_piece", {0,0,0,1,1,1,1,2}};
	s_piece p18 = {"z_piece", {0,0,1,0,1,1,2,1}};
	s_piece p19 = {"zr_piece", {1,0,0,1,1,1,0,2}};

}

char	*get_tetid(int *tet) // finds the name of the tetrimino by comparing it to the arrays in fillit.h
{
	char	*name;
	name = NULL;
//	give_value_to_tet();
	s_piece p1 = {"i_piece", {0,0,0,1,0,2,0,3}};
	s_piece p2 = {"ih_piece", {0,0,1,0,2,0,3,0}};
	s_piece p3 = {"o_piece", {0,0,1,0,0,1,1,1}};
	s_piece p4 = {"l_piece", {0,0,0,1,0,2,1,2}};
	s_piece p5 = {"lr_piece", {0,0,1,0,2,0,0,1}};
	s_piece p6 = {"ld_piece", {0,0,1,0,1,1,1,2}};
	s_piece p7 = {"ll_piece", {2,0,0,1,1,1,2,1}};
	s_piece p8 = {"j_piece", {1,0,1,1,0,2,1,2}};
	s_piece p9 = {"jr_piece", {0,0,0,1,1,1,2,1}};
	s_piece p10 = {"jd_piece", {0,0,1,0,0,1,0,2}};
	s_piece p11 = {"jl_piece", {0,0,1,0,2,0,2,1}};
	s_piece p12 = {"t_piece", {1,0,0,1,1,1,2,1}};
	s_piece p13 = {"tr_piece", {0,0,0,1,1,1,0,2}};
	s_piece p14 = {"td_piece", {0,0,1,0,2,0,1,1}};
	s_piece p15 = {"tl_piece", {1,0,0,1,1,1,1,2}};
	s_piece p16 = {"s_piece", {1,0,2,0,0,1,1,1}};
	s_piece p17 = {"sr_piece", {0,0,0,1,1,1,1,2}};
	s_piece p18 = {"z_piece", {0,0,1,0,1,1,2,1}};
	s_piece p19 = {"zr_piece", {1,0,0,1,1,1,0,2}};
	if (tetcmp(tet, p1.coord, sizeof(tet)) == 1)
	name = "i_piece";
	if (tetcmp(tet, p2.coord, sizeof(tet)) == 1)
	name = "ih_piece";
	if (tetcmp(tet, p3.coord, sizeof(tet)) == 1)
	name = "o_piece";
	if (tetcmp(tet, p4.coord, sizeof(tet)) == 1)
	name = "l_piece";
	if (tetcmp(tet, p5.coord, sizeof(tet)) == 1)
	name = "lr_piece";
	if (tetcmp(tet, p6.coord, sizeof(tet)) == 1)
	name = "ld_piece";
	if (tetcmp(tet, p7.coord, sizeof(tet)) == 1)
	name = "ll_piece";
	if (tetcmp(tet, p8.coord, sizeof(tet)) == 1)
	name = "j_piece";
	if (tetcmp(tet, p9.coord, sizeof(tet)) == 1)
	name = "jr_piece";
	if (tetcmp(tet, p10.coord, sizeof(tet)) == 1)
	name = "jd_piece";
	if (tetcmp(tet, p11.coord, sizeof(tet)) == 1)
	name = "jl_piece";
	if (tetcmp(tet, p12.coord, sizeof(tet)) == 1)
	name = "t_piece";
	if (tetcmp(tet, p13.coord, sizeof(tet)) == 1)
	name = "tr_piece";
	if (tetcmp(tet, p14.coord, sizeof(tet)) == 1)
	name = "td_piece";
	if (tetcmp(tet, p15.coord, sizeof(tet)) == 1)
	name = "tl_piece";
	if (tetcmp(tet, p16.coord, sizeof(tet)) == 1)
	name = "s_piece";
	if (tetcmp(tet, p17.coord, sizeof(tet)) == 1)
	name = "sr_piece";
	if (tetcmp(tet, p18.coord, sizeof(tet)) == 1)
	name = "z_piece";
	if (tetcmp(tet, p19.coord, sizeof(tet)) == 1)
	name = "zr_piece";
	printf("it's a match with : %s\n", name);
	return (name);
}

int	tetcmp(int *tet, int *libtet, int n)
{
	int	i;

	i = 0;
	printf("tet inside tet cmp = ");
	while (i < n)
	{
		printf("%d", tet[i]);
		if (tet[i] != libtet[i])
			return (-1);
		i++;
	}
	return (1);
}

int		*convert_id(char *name)
{
	int	*tet;
	s_piece p1 = {"i_piece", {0,0,0,1,0,2,0,3}};
	s_piece p2 = {"ih_piece", {0,0,1,0,2,0,3,0}};
	s_piece p3 = {"o_piece", {0,0,1,0,0,1,1,1}};
	s_piece p4 = {"l_piece", {0,0,0,1,0,2,1,2}};
	s_piece p5 = {"lr_piece", {0,0,1,0,2,0,0,1}};
	s_piece p6 = {"ld_piece", {0,0,1,0,1,1,1,2}};
	s_piece p7 = {"ll_piece", {2,0,0,1,1,1,2,1}};
	s_piece p8 = {"j_piece", {1,0,1,1,0,2,1,2}};
	s_piece p9 = {"jr_piece", {0,0,0,1,1,1,2,1}};
	s_piece p10 = {"jd_piece", {0,0,1,0,0,1,0,2}};
	s_piece p11 = {"jl_piece", {0,0,1,0,2,0,2,1}};
	s_piece p12 = {"t_piece", {1,0,0,1,1,1,2,1}};
	s_piece p13 = {"tr_piece", {0,0,0,1,1,1,0,2}};
	s_piece p14 = {"td_piece", {0,0,1,0,2,0,1,1}};
	s_piece p15 = {"tl_piece", {1,0,0,1,1,1,1,2}};
	s_piece p16 = {"s_piece", {1,0,2,0,0,1,1,1}};
	s_piece p17 = {"sr_piece", {0,0,0,1,1,1,1,2}};
	s_piece p18 = {"z_piece", {0,0,1,0,1,1,2,1}};
	s_piece p19 = {"zr_piece", {1,0,0,1,1,1,0,2}};
	tet = (int *)malloc(sizeof(int) * 8);

	(ft_strcmp(name, "i_piece") == 0) && (dup_coord(tet, p1.coord));
	(ft_strcmp(name, "ih_piece") == 0) && (dup_coord(tet, p2.coord));
	(ft_strcmp(name, "o_piece") == 0) && (dup_coord(tet, p3.coord));
	(ft_strcmp(name, "l_piece") == 0) && (dup_coord(tet, p4.coord));
	(ft_strcmp(name, "lr_piece") == 0) && (dup_coord(tet, p5.coord));
	(ft_strcmp(name, "ld_piece") == 0) && (dup_coord(tet, p6.coord));
	(ft_strcmp(name, "ll_piece") == 0) && (dup_coord(tet, p7.coord));
	(ft_strcmp(name, "j_piece") == 0) && (dup_coord(tet, p8.coord));
	(ft_strcmp(name, "jr_piece") == 0) && (dup_coord(tet, p9.coord));
	(ft_strcmp(name, "jd_piece") == 0) && (dup_coord(tet, p10.coord));
	(ft_strcmp(name, "jl_piece") == 0) && (dup_coord(tet, p11.coord));
	(ft_strcmp(name, "t_piece") == 0) && (dup_coord(tet, p12.coord));
	(ft_strcmp(name, "tr_piece") == 0) && (dup_coord(tet, p13.coord));
	(ft_strcmp(name, "td_piece") == 0) && (dup_coord(tet, p14.coord));
	(ft_strcmp(name, "tl_piece") == 0) && (dup_coord(tet, p15.coord));
	(ft_strcmp(name, "s_piece") == 0) && (dup_coord(tet, p16.coord));
	(ft_strcmp(name, "sr_piece") == 0) && (dup_coord(tet, p17.coord));
	(ft_strcmp(name, "z_piece") == 0) && (dup_coord(tet, p18.coord));
	(ft_strcmp(name, "zr_piece") == 0) && (dup_coord(tet, p19.coord));
	int i;
	i = 0;
	printf("tet inside convert id = ");
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
